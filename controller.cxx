
#include <algorithm>
#include <iostream>

// #include <dds/sub/ddssub.hpp>
// #include <dds/core/ddscore.hpp>
#include <dds/dds.hpp> 

#include "DataTypeDefinitions.hpp"

bool check_if_command_needs_to_be_sent(
        float received_proximity,
        float previously_received_proximity) {

    bool send_brake_command_sample = false;

    if (
        ((50 < previously_received_proximity && previously_received_proximity <= 100) &&
        (50 < received_proximity && received_proximity <= 100)) ||
        ((0 <= previously_received_proximity && previously_received_proximity <= 50) &&
        (0 <= received_proximity && received_proximity <= 50)) ||
        ((100 < previously_received_proximity) &&
        (100 < received_proximity))) {

        send_brake_command_sample = false;

    } else {
        send_brake_command_sample = true;
    }
    return send_brake_command_sample;
}


int ProximityData_process_data(
        dds::sub::DataReader<ProximityData>& ProximityData_reader,
        dds::pub::DataWriter<BrakeCommand>& BrakeCommand_writer,
        float *previously_received_proximity)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<ProximityData> samples = ProximityData_reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            count++;

            auto device_id = sample.data().device_id();
            auto proximity = sample.data().proximity();

            std::cout << "INFO: Received data" << std::endl;
            std::cout << "\tSensor ID = " << device_id << std::endl;
            std::cout << "\tProximity (m) = " << proximity << std::endl << std::endl;

            // Decide if we need to send a sample depending on if the brake intensity needs to be updated
            bool send_brake_command_sample = check_if_command_needs_to_be_sent(
                    proximity,
                    *previously_received_proximity);

            BrakeCommand BrakeCommand_sample;
            BrakeCommand_sample.device_id("Actuator1234");
            if (send_brake_command_sample == true) {

                if (proximity > 100) {
                    BrakeCommand_sample.brake_intensity(0);

                } else if (50 < proximity && proximity <= 100) {
                    BrakeCommand_sample.brake_intensity(50);

                } else {
                    BrakeCommand_sample.brake_intensity(100);
                }

                BrakeCommand_writer.write(BrakeCommand_sample);

                *previously_received_proximity = proximity;
            }
        }
 
    }

    return count; 
} // The LoanedSamples destructor returns the loan

int DeviceStatus_process_data(dds::sub::DataReader<DeviceStatus>& reader) {
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<DeviceStatus> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            count++;
            std::cout << sample << std::endl;
        }
    }

    return count; 

}

int subscriber_main(int domain_id, int sample_count)
{
    // because we are using USER_QOS_PROFILE.xml, this default works
    dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(
            domain_id,
            qos_provider.participant_qos(SYSTEM_QOS_LIBRARY_NAME + "::" + PARTICIPANT_BASE_QOS_PROFILE_NAME));

    // BrakeCommand specifics
    dds::topic::Topic<BrakeCommand> BrakeCommand_topic (participant, BRAKE_COMMAND_TOPIC_NAME);

    dds::pub::DataWriter<BrakeCommand> BrakeCommand_writer(
            dds::pub::Publisher(participant),
            BrakeCommand_topic,
            qos_provider.datawriter_qos(DATA_QOS_LIBRARY_NAME + "::" + COMMAND_QOS_PROFILE_NAME));

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<ProximityData> ProximityData_topic(participant, PROXIMITY_DATA_TOPIC_NAME);

    dds::sub::Subscriber subscriber(participant);
    // Create a DataReader with default Qos (Subscriber created in-line)
    dds::sub::DataReader<ProximityData> ProximityData_reader(
            subscriber, 
            ProximityData_topic,
            qos_provider.datareader_qos(DATA_QOS_LIBRARY_NAME + "::" + STREAMING_DATA_QOS_PROFILE_NAME));

    // get the readers StatusCondition
    dds::core::cond::StatusCondition status_condition(ProximityData_reader);
    status_condition.enabled_statuses(
            dds::core::status::StatusMask::requested_deadline_missed());

    status_condition->handler([&ProximityData_reader]() {
        dds::core::status::StatusMask status_mask = ProximityData_reader.status_changes();

        if ((status_mask & dds::core::status::StatusMask::requested_deadline_missed()).any()) {
            dds::core::status::RequestedDeadlineMissedStatus st =
                    ProximityData_reader.requested_deadline_missed_status();
            if (st.total_count_change() > 0) {

                ProximityData the_key_holder;
                ProximityData_reader.key_value(the_key_holder, st.last_instance_handle());
                std::cout << "WARN: Missed deadline:\n"
                          << "\tTopic = '" << ProximityData_reader.topic_description().name() << "'\n"
                          << "\tInstance = " << the_key_holder.device_id()  
                          << std::endl;
            }
        }

    });

    // Create a ReadCondition for any data on this reader and associate a handler
    int count = 0;
    float previously_received_proximity = 1000.0;
    dds::sub::cond::ReadCondition ProximityData_read_condition(
        ProximityData_reader,
        dds::sub::status::DataState::any(),
        [&ProximityData_reader, &BrakeCommand_writer, &previously_received_proximity, &count]()
    {
        count += ProximityData_process_data(ProximityData_reader, BrakeCommand_writer, &previously_received_proximity);
    }
    );

    // Create DeviceStatus topic
    dds::topic::Topic<DeviceStatus> DeviceStatus_topic(participant, DEVICE_STATUS_TOPIC_NAME);
    // Create DR for DeviceStatus topic
    dds::sub::DataReader<DeviceStatus> DeviceStatus_reader(
            subscriber, 
            DeviceStatus_topic,
            qos_provider.datareader_qos(DATA_QOS_LIBRARY_NAME + "::" + STATE_DATA_QOS_PROFILE_NAME));    

    dds::sub::cond::ReadCondition DeviceStatus_read_condition(
        DeviceStatus_reader,
        dds::sub::status::DataState::any(),
        [&DeviceStatus_reader, &count](/* dds::core::cond::Condition condition */)
    {
        count += DeviceStatus_process_data(DeviceStatus_reader);
    }
    );

    // Create a WaitSet and attach the ReadCondition
    dds::core::cond::WaitSet waitset;
    waitset += ProximityData_read_condition;
    waitset += status_condition;
    waitset += DeviceStatus_read_condition;
    

    while (count < sample_count || sample_count == 0) {
        // Dispatch will call the handlers associated to the WaitSet conditions
        // when they activate
        std::cout << "INFO: controller dispatching waitset" << std::endl;

        waitset.dispatch(dds::core::Duration(4)); // Wait up to 4s each time
    }
    return 1;
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        subscriber_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

