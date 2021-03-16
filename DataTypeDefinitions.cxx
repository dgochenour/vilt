

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DataTypeDefinitions.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "DataTypeDefinitions.hpp"
#include "DataTypeDefinitionsPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- ProximityData: 

ProximityData::ProximityData() :
    m_sensor_id_ ("") ,
    m_proximity_ (0.0f)  {
}   

ProximityData::ProximityData (
    const std::string& sensor_id,
    float proximity)
    :
        m_sensor_id_( sensor_id ),
        m_proximity_( proximity ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ProximityData::ProximityData(ProximityData&& other_) OMG_NOEXCEPT  :m_sensor_id_ (std::move(other_.m_sensor_id_))
,
m_proximity_ (std::move(other_.m_proximity_))
{
} 

ProximityData& ProximityData::operator=(ProximityData&&  other_) OMG_NOEXCEPT {
    ProximityData tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void ProximityData::swap(ProximityData& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_sensor_id_, other_.m_sensor_id_);
    swap(m_proximity_, other_.m_proximity_);
}  

bool ProximityData::operator == (const ProximityData& other_) const {
    if (m_sensor_id_ != other_.m_sensor_id_) {
        return false;
    }
    if (m_proximity_ != other_.m_proximity_) {
        return false;
    }
    return true;
}
bool ProximityData::operator != (const ProximityData& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ProximityData& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "sensor_id: " << sample.sensor_id()<<", ";
    o << "proximity: " << std::setprecision(9) <<sample.proximity() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< ProximityData > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ProximityData_g_tc_sensor_id_string;

                static DDS_TypeCode_Member ProximityData_g_tc_members[2]=
                {

                    {
                        (char *)"sensor_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"proximity",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ProximityData_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ProximityData", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ProximityData_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ProximityData*/

                if (is_initialized) {
                    return &ProximityData_g_tc;
                }

                ProximityData_g_tc_sensor_id_string = initialize_string_typecode(((SENSOR_ID_MAX_LENGTH)));

                ProximityData_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ProximityData_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ProximityData_g_tc_sensor_id_string;
                ProximityData_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                ProximityData_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ProximityData_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ProximityData_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                ProximityData_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                ProximityData_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                ProximityData_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                ProximityData_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                ProximityData_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                ProximityData_g_tc._data._sampleAccessInfo = sample_access_info();
                ProximityData_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ProximityData_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ProximityData *sample;

                static RTIXCdrMemberAccessInfo ProximityData_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ProximityData_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ProximityData_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ProximityData);
                if (sample == NULL) {
                    return NULL;
                }

                ProximityData_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sensor_id() - (char *)sample);

                ProximityData_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->proximity() - (char *)sample);

                ProximityData_g_sampleAccessInfo.memberAccessInfos = 
                ProximityData_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ProximityData);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        ProximityData_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        ProximityData_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ProximityData_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ProximityData_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ProximityData >;

                ProximityData_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ProximityData_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ProximityData_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ProximityData_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< ProximityData >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ProximityData >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ProximityData >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ProximityDataPlugin_new,
                ProximityDataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ProximityData >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ProximityData& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ProximityDataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ProximityDataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ProximityData >::from_cdr_buffer(ProximityData& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ProximityDataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ProximityData from cdr buffer");
        }

        void topic_type_support< ProximityData >::reset_sample(ProximityData& sample) 
        {
            sample.sensor_id("");
            sample.proximity(0.0f);
        }

        void topic_type_support< ProximityData >::allocate_sample(ProximityData& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.sensor_id(),  -1, (SENSOR_ID_MAX_LENGTH));
        }

    }
}  

