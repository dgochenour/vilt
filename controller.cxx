
#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
// Or simply include <dds/dds.hpp> 

#include "DataTypeDefinitions.hpp"

int process_data(dds::sub::DataReader<ProximityData>& reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<ProximityData> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            count++;
            std::cout << "INFO: Received Data" << std::endl;
            std::cout << "\tSensor ID = " << sample.data().device_id() << std::endl;
            std::cout << "\tProximity (m) = " << sample.data().proximity() << std::endl;

        }   
    }

    return count; 
} // The LoanedSamples destructor returns the loan

int subscriber_main(int domain_id, int sample_count)
{
    // because we are using USER_QOS_PROFILE.xml, this default works
    dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(
            domain_id,
            qos_provider.participant_qos("System_Library::ParticipantBase"));

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<ProximityData> topic(participant, PROXIMITY_DATA_TOPIC_NAME);

    // Create a DataReader with default Qos (Subscriber created in-line)
    dds::sub::DataReader<ProximityData> reader(
            dds::sub::Subscriber(participant), 
            topic,
            qos_provider.datareader_qos("Data_Library::StreamingData"));

    // get the readers StatusCondition
    dds::core::cond::StatusCondition status_condition(reader);
    status_condition.enabled_statuses(
            dds::core::status::StatusMask::requested_deadline_missed());

    status_condition->handler([&reader]() {
        dds::core::status::StatusMask status_mask = reader.status_changes();

        if ((status_mask & dds::core::status::StatusMask::requested_deadline_missed()).any()) {
            dds::core::status::RequestedDeadlineMissedStatus st =
                    reader.requested_deadline_missed_status();
            if (st.total_count_change() > 0) {

                ProximityData the_key_holder;
                reader.key_value(the_key_holder, st.last_instance_handle());
                std::cout << "WARN: Missed deadline:\n"
                          << "\tTopic = '" << reader.topic_description().name() << "'\n"
                          << "\tInstance = " << the_key_holder.device_id()  
                          << std::endl;
            }
        }

    });

    // Create a ReadCondition for any data on this reader and associate a handler
    int count = 0;
    dds::sub::cond::ReadCondition read_condition(
        reader,
        dds::sub::status::DataState::any(),
        [&reader, &count](/* dds::core::cond::Condition condition */)
    {
        count += process_data(reader);
    }
    );

    // Create a WaitSet and attach the ReadCondition
    dds::core::cond::WaitSet waitset;
    waitset += read_condition;
    waitset += status_condition;

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

