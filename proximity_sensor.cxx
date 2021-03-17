

#include <iostream>


#include <dds/dds.hpp>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include "DataTypeDefinitions.hpp"

void publisher_main(int domain_id, int sample_count)
{
    // because we are using USER_QOS_PROFILE.xml, this default works
    dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(
            domain_id,
            qos_provider.participant_qos(SYSTEM_QOS_LIBRARY_NAME + "::" + PARTICIPANT_BASE_QOS_PROFILE_NAME));

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<ProximityData> ProximityData_topic (participant, PROXIMITY_DATA_TOPIC_NAME);

    // Create a DataWriter with default Qos
    dds::pub::Publisher publisher(participant);
    dds::pub::DataWriter<ProximityData> ProximityData_writer(
            publisher, 
            ProximityData_topic,
            qos_provider.datawriter_qos(DATA_QOS_LIBRARY_NAME + "::" + STREAMING_DATA_QOS_PROFILE_NAME));

    // Create Device Status topic
    dds::topic::Topic<DeviceStatus> DeviceStatus_topic (participant, DEVICE_STATUS_TOPIC_NAME);
    // Create DW for Device Status Topic
    dds::pub::DataWriter<DeviceStatus> DeviceStatus_writer(
            publisher,
            DeviceStatus_topic,
            qos_provider.datawriter_qos(DATA_QOS_LIBRARY_NAME + "::" + STATE_DATA_QOS_PROFILE_NAME));            

    DeviceStatus DeviceStatus_sample;
    DeviceStatus_sample.device_id("Sensor1234");
    DeviceStatus_sample.device_kind()._d(DeviceKind::SENSOR);
    DeviceStatus_sample.device_kind().this_sensor(SensorKind::PROXIMITY);
    DeviceStatus_sample.device_status(DeviceStatusEnum::ON);
    DeviceStatus_sample.information("?");

    DeviceStatus_writer.write(DeviceStatus_sample);

    ProximityData ProximityData_sample;

    ProximityData_sample.device_id("Sensor1234");
    float sensor_proximity = 150;
    float proximity_step = 1;

    for (int count = 0; count < sample_count || sample_count == 0; count++) {

        // Modify the data to be written here
        if (sensor_proximity == 0 || sensor_proximity == 300) {
            proximity_step *= -1;
        }
        ProximityData_sample.proximity(sensor_proximity);

        std::cout << "Writing ProximityData, count " << count << std::endl;

        ProximityData_writer.write(ProximityData_sample);
        sensor_proximity += proximity_step;

        rti::util::sleep(dds::core::Duration(0, 100000000));
    }
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
        publisher_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

