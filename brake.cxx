#include <algorithm>
#include <iostream>

#include <dds/dds.hpp> 

#include "DataTypeDefinitions.hpp"

class MyReaderListener : public dds::sub::NoOpDataReaderListener<BrakeCommand> {
public:
    void on_subscription_matched(dds::sub::DataReader<BrakeCommand> &reader,
        const dds::core::status::SubscriptionMatchedStatus &status) {
            std::cout << "INFO: Matched a DW, total count is: " << status.current_count() << std::endl;
        }    
};

int BrakeCommand_process_data(dds::sub::DataReader<BrakeCommand>& reader) {
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<BrakeCommand> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            count++;
            std::cout << sample << std::endl;
        }
    }
    return count; 
} // loan is returned when samples goes out of scope


int brake_main(int domain_id, int sample_count) {

    std::string my_device_id = "Actuator1234";

    // because we are using USER_QOS_PROFILE.xml, this default works
    dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(
            domain_id,
            qos_provider.participant_qos(SYSTEM_QOS_LIBRARY_NAME + "::" + PARTICIPANT_BASE_QOS_PROFILE_NAME));

    // BrakeCommand specifics
    dds::topic::Topic<BrakeCommand> BrakeCommand_topic (participant, BRAKE_COMMAND_TOPIC_NAME);  

    MyReaderListener listener;

    std::vector<std::string> parameters(1);
    parameters[0] = my_device_id;
    dds::topic::Filter filter("device_id MATCH %0", parameters);

    filter->name(rti::topic::stringmatch_filter_name());

    dds::topic::ContentFilteredTopic<BrakeCommand> cft(
        BrakeCommand_topic,
        "ContentFilteredTopic",
        filter
    );

    dds::sub::DataReader<BrakeCommand> BrakeCommand_reader(
        dds::sub::Subscriber(participant),
        /*cft*/ BrakeCommand_topic,
        qos_provider.datareader_qos(DATA_QOS_LIBRARY_NAME + "::" + COMMAND_QOS_PROFILE_NAME),
        &listener,
        dds::core::status::StatusMask::subscription_matched()
    );  

    int count = 0;
    dds::sub::cond::ReadCondition BrakeCommand_read_condition(
        BrakeCommand_reader,
        dds::sub::status::DataState::any(),
        [&BrakeCommand_reader, &count]() {
            count += BrakeCommand_process_data(BrakeCommand_reader);
        }
    );

    dds::core::cond::WaitSet waitset;
    waitset += BrakeCommand_read_condition;

    // Create Device Status topic
    dds::topic::Topic<DeviceStatus> DeviceStatus_topic (participant, DEVICE_STATUS_TOPIC_NAME);
    // Create DW for Device Status Topic
    dds::pub::DataWriter<DeviceStatus> DeviceStatus_writer(
            dds::pub::Publisher(participant),
            DeviceStatus_topic,
            qos_provider.datawriter_qos(DATA_QOS_LIBRARY_NAME + "::" + STATE_DATA_QOS_PROFILE_NAME));  



    DeviceStatus DeviceStatus_sample;
    DeviceStatus_sample.device_id(my_device_id);
    DeviceStatus_sample.device_kind()._d(DeviceKind::ACTUATOR);
    DeviceStatus_sample.device_kind().this_actuator(ActuatorKind::BRAKE);
    DeviceStatus_sample.device_status(DeviceStatusEnum::ON);
    DeviceStatus_sample.information("the brake");

    DeviceStatus_writer.write(DeviceStatus_sample);    

    while (count < sample_count || sample_count == 0) {
        
        std::cout << "brake_main sleeping for 4s" << std::endl;
        waitset.dispatch(dds::core::Duration(4,0));

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

    try {
        brake_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
