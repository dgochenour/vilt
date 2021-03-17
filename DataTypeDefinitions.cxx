

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
    m_device_id_ ("") ,
    m_proximity_ (0.0f)  {
}   

ProximityData::ProximityData (
    const std::string& device_id,
    float proximity)
    :
        m_device_id_( device_id ),
        m_proximity_( proximity ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ProximityData::ProximityData(ProximityData&& other_) OMG_NOEXCEPT  :m_device_id_ (std::move(other_.m_device_id_))
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
    swap(m_device_id_, other_.m_device_id_);
    swap(m_proximity_, other_.m_proximity_);
}  

bool ProximityData::operator == (const ProximityData& other_) const {
    if (m_device_id_ != other_.m_device_id_) {
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
    o << "device_id: " << sample.device_id()<<", ";
    o << "proximity: " << std::setprecision(9) <<sample.proximity() ;
    o <<"]";
    return o;
}

std::ostream& operator << (std::ostream& o,const DeviceKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case DeviceKind::SENSOR:
        o << "DeviceKind::SENSOR" << " ";
        break;
        case DeviceKind::ACTUATOR:
        o << "DeviceKind::ACTUATOR" << " ";
        break;
    }
    return o;
}

std::ostream& operator << (std::ostream& o,const SensorKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case SensorKind::TEMPERATURE:
        o << "SensorKind::TEMPERATURE" << " ";
        break;
        case SensorKind::PROXIMITY:
        o << "SensorKind::PROXIMITY" << " ";
        break;
        case SensorKind::PRESSURE:
        o << "SensorKind::PRESSURE" << " ";
        break;
    }
    return o;
}

std::ostream& operator << (std::ostream& o,const ActuatorKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case ActuatorKind::BRAKE:
        o << "ActuatorKind::BRAKE" << " ";
        break;
        case ActuatorKind::THROTTLE:
        o << "ActuatorKind::THROTTLE" << " ";
        break;
        case ActuatorKind::LIGHTS:
        o << "ActuatorKind::LIGHTS" << " ";
        break;
    }
    return o;
}

// ---- DeviceKindUnion: 

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DeviceKindUnion::DeviceKindUnion(DeviceKindUnion&& other_) OMG_NOEXCEPT 
{
    _d(std::move(other_._d()));
    switch(::rti::topic::cdr::integer_case(_d())){
        case (DeviceKind::SENSOR):
            {  
                this_sensor( std::move(other_.this_sensor()));
        } break;
        case (DeviceKind::ACTUATOR):
            {  
                this_actuator( std::move(other_.this_actuator()));
        } break;

    }

}

DeviceKindUnion& DeviceKindUnion::operator=(DeviceKindUnion&&  other_) OMG_NOEXCEPT {
    DeviceKindUnion tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif 

DeviceKindUnion::Union_::Union_() :
    m_this_sensor_(SensorKind::TEMPERATURE) ,
    m_this_actuator_(ActuatorKind::BRAKE)  {
}

DeviceKindUnion::Union_::Union_(
    const SensorKind& this_sensor,
    const ActuatorKind& this_actuator)
    :
        m_this_sensor_( this_sensor ),
        m_this_actuator_( this_actuator ) {
}

DeviceKindUnion::DeviceKindUnion() :m_d_(default_discriminator())
{
}

void DeviceKindUnion::swap(DeviceKindUnion& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap (m_d_,other_.m_d_);
    switch(::rti::topic::cdr::integer_case(_d())){
        case (DeviceKind::SENSOR):
            {  
                swap(m_u_.m_this_sensor_, other_.m_u_.m_this_sensor_);
        } break;
        case (DeviceKind::ACTUATOR):
            {  
                swap(m_u_.m_this_actuator_, other_.m_u_.m_this_actuator_);
        } break;

    }
    if (_d() != other_._d()){
        switch(::rti::topic::cdr::integer_case(other_._d())){
            case (DeviceKind::SENSOR):
                {  
                    swap(m_u_.m_this_sensor_, other_.m_u_.m_this_sensor_);
            } break;
            case (DeviceKind::ACTUATOR):
                {  
                    swap(m_u_.m_this_actuator_, other_.m_u_.m_this_actuator_);
            } break;

        }
    }
}  

bool DeviceKindUnion::operator == (const DeviceKindUnion& other_) const {
    if (_d() != other_._d()){
        return false;
    }
    switch(::rti::topic::cdr::integer_case(_d())){
        case (DeviceKind::SENSOR):
            {  
                if ( m_u_.m_this_sensor_ != other_.m_u_.m_this_sensor_) {
                    return false;
            }
        } break ;
        case (DeviceKind::ACTUATOR):
            {  
                if ( m_u_.m_this_actuator_ != other_.m_u_.m_this_actuator_) {
                    return false;
            }
        } break ;
    }
    return true;
}
bool DeviceKindUnion::operator != (const DeviceKindUnion& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DeviceKindUnion& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "_d: " << sample._d() <<", ";
    switch(::rti::topic::cdr::integer_case(sample._d())){
        case (DeviceKind::SENSOR):
            {  
                o << "this_sensor: " << sample.this_sensor()<<", ";
        } break ;
        case (DeviceKind::ACTUATOR):
            {  
                o << "this_actuator: " << sample.this_actuator() ;        } break ;

    }
    o <<"]";
    return o;
}

DeviceKind DeviceKindUnion::default_discriminator() {
    return DeviceKind(static_cast< DeviceKind::type >(0));
}  

std::ostream& operator << (std::ostream& o,const DeviceStatusEnum& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case DeviceStatusEnum::ON:
        o << "DeviceStatusEnum::ON" << " ";
        break;
        case DeviceStatusEnum::OFF:
        o << "DeviceStatusEnum::OFF" << " ";
        break;
    }
    return o;
}

// ---- DeviceStatus: 

DeviceStatus::DeviceStatus() :
    m_device_id_ ("") ,
    m_device_status_(DeviceStatusEnum::ON) ,
    m_information_ ("")  {
}   

DeviceStatus::DeviceStatus (
    const std::string& device_id,
    const DeviceKindUnion& device_kind,
    const DeviceStatusEnum& device_status,
    const std::string& information)
    :
        m_device_id_( device_id ),
        m_device_kind_( device_kind ),
        m_device_status_( device_status ),
        m_information_( information ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DeviceStatus::DeviceStatus(DeviceStatus&& other_) OMG_NOEXCEPT  :m_device_id_ (std::move(other_.m_device_id_))
,
m_device_kind_ (std::move(other_.m_device_kind_))
,
m_device_status_ (std::move(other_.m_device_status_))
,
m_information_ (std::move(other_.m_information_))
{
} 

DeviceStatus& DeviceStatus::operator=(DeviceStatus&&  other_) OMG_NOEXCEPT {
    DeviceStatus tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DeviceStatus::swap(DeviceStatus& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_device_id_, other_.m_device_id_);
    swap(m_device_kind_, other_.m_device_kind_);
    swap(m_device_status_, other_.m_device_status_);
    swap(m_information_, other_.m_information_);
}  

bool DeviceStatus::operator == (const DeviceStatus& other_) const {
    if (m_device_id_ != other_.m_device_id_) {
        return false;
    }
    if (m_device_kind_ != other_.m_device_kind_) {
        return false;
    }
    if (m_device_status_ != other_.m_device_status_) {
        return false;
    }
    if (m_information_ != other_.m_information_) {
        return false;
    }
    return true;
}
bool DeviceStatus::operator != (const DeviceStatus& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DeviceStatus& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "device_id: " << sample.device_id()<<", ";
    o << "device_kind: " << sample.device_kind()<<", ";
    o << "device_status: " << sample.device_status()<<", ";
    o << "information: " << sample.information() ;
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

                static DDS_TypeCode ProximityData_g_tc_device_id_string;

                static DDS_TypeCode_Member ProximityData_g_tc_members[2]=
                {

                    {
                        (char *)"device_id",/* Member name */
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

                ProximityData_g_tc_device_id_string = initialize_string_typecode(((DEVICE_ID_MAX_LENGTH)));

                ProximityData_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ProximityData_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ProximityData_g_tc_device_id_string;
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
                (RTIXCdrUnsignedLong) ((char *)&sample->device_id() - (char *)sample);

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

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DeviceKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DeviceKind_g_tc_members[2]=
                {

                    {
                        (char *)"SENSOR",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        DeviceKind::SENSOR, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ACTUATOR",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        DeviceKind::ACTUATOR, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DeviceKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        DeviceKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DeviceKind*/

                if (is_initialized) {
                    return &DeviceKind_g_tc;
                }

                DeviceKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                DeviceKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DeviceKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                DeviceKind_g_tc._data._sampleAccessInfo = sample_access_info();
                DeviceKind_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DeviceKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo DeviceKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DeviceKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DeviceKind_g_sampleAccessInfo;
                }

                DeviceKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                DeviceKind_g_sampleAccessInfo.memberAccessInfos = 
                DeviceKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DeviceKind);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DeviceKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DeviceKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DeviceKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DeviceKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DeviceKind >;

                DeviceKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DeviceKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DeviceKind_g_typePlugin = 
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

                return &DeviceKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< DeviceKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DeviceKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< SensorKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member SensorKind_g_tc_members[3]=
                {

                    {
                        (char *)"TEMPERATURE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        SensorKind::TEMPERATURE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PROXIMITY",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        SensorKind::PROXIMITY, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PRESSURE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        SensorKind::PRESSURE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode SensorKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"SensorKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        SensorKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for SensorKind*/

                if (is_initialized) {
                    return &SensorKind_g_tc;
                }

                SensorKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                SensorKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                SensorKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                SensorKind_g_tc._data._sampleAccessInfo = sample_access_info();
                SensorKind_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &SensorKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo SensorKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo SensorKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &SensorKind_g_sampleAccessInfo;
                }

                SensorKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                SensorKind_g_sampleAccessInfo.memberAccessInfos = 
                SensorKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(SensorKind);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        SensorKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        SensorKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                SensorKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                SensorKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< SensorKind >;

                SensorKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &SensorKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin SensorKind_g_typePlugin = 
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

                return &SensorKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< SensorKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< SensorKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< ActuatorKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ActuatorKind_g_tc_members[3]=
                {

                    {
                        (char *)"BRAKE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        ActuatorKind::BRAKE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"THROTTLE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        ActuatorKind::THROTTLE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"LIGHTS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        ActuatorKind::LIGHTS, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ActuatorKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ActuatorKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        ActuatorKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ActuatorKind*/

                if (is_initialized) {
                    return &ActuatorKind_g_tc;
                }

                ActuatorKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                ActuatorKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ActuatorKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                ActuatorKind_g_tc._data._sampleAccessInfo = sample_access_info();
                ActuatorKind_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ActuatorKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ActuatorKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ActuatorKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ActuatorKind_g_sampleAccessInfo;
                }

                ActuatorKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ActuatorKind_g_sampleAccessInfo.memberAccessInfos = 
                ActuatorKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ActuatorKind);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        ActuatorKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        ActuatorKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ActuatorKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ActuatorKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ActuatorKind >;

                ActuatorKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ActuatorKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ActuatorKind_g_typePlugin = 
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

                return &ActuatorKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< ActuatorKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ActuatorKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DeviceKindUnion > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DeviceKindUnion_g_tc_members[2]=
                {

                    {
                        (char *)"this_sensor",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        1, /* Number of labels */
                        (DeviceKind::SENSOR), /* First label cpp11stl (DeviceKind::SENSOR) */
                        NULL, /* Labels (it is NULL when there is only one label)*/
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"this_actuator",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        1, /* Number of labels */
                        (DeviceKind::ACTUATOR), /* First label cpp11stl (DeviceKind::ACTUATOR) */
                        NULL, /* Labels (it is NULL when there is only one label)*/
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DeviceKindUnion_g_tc =
                {{
                        DDS_TK_UNION, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceKindUnion", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        DeviceKindUnion_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DeviceKindUnion*/

                if (is_initialized) {
                    return &DeviceKindUnion_g_tc;
                }

                DeviceKindUnion_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DeviceKindUnion_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< SensorKind>::get().native();
                DeviceKindUnion_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ActuatorKind>::get().native();

                /* Initialize the values for member annotations. */
                DeviceKindUnion_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DeviceKindUnion_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                DeviceKindUnion_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DeviceKindUnion_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                /* Discriminator type code */
                DeviceKindUnion_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< DeviceKind>::get().native();

                DeviceKindUnion_g_tc._data._sampleAccessInfo = sample_access_info();
                DeviceKindUnion_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DeviceKindUnion_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DeviceKindUnion *sample;

                static RTIXCdrMemberAccessInfo DeviceKindUnion_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DeviceKindUnion_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DeviceKindUnion_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DeviceKindUnion);
                if (sample == NULL) {
                    return NULL;
                }

                DeviceKindUnion_g_memberAccessInfos[0].bindingMemberValueOffset[0] =
                (RTIXCdrUnsignedLong) ((char *)&sample->_d() - (char *)sample);

                sample->_d() = (DeviceKind::SENSOR);
                DeviceKindUnion_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->this_sensor() - (char *)sample);

                sample->_d() = (DeviceKind::ACTUATOR);
                DeviceKindUnion_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->this_actuator() - (char *)sample);

                DeviceKindUnion_g_sampleAccessInfo.memberAccessInfos = 
                DeviceKindUnion_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DeviceKindUnion);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DeviceKindUnion_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DeviceKindUnion_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DeviceKindUnion_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DeviceKindUnion_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DeviceKindUnion >;

                DeviceKindUnion_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DeviceKindUnion_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DeviceKindUnion_g_typePlugin = 
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

                return &DeviceKindUnion_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::UnionType& dynamic_type< DeviceKindUnion >::get()
        {
            return static_cast<const ::dds::core::xtypes::UnionType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DeviceKindUnion >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DeviceStatusEnum > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DeviceStatusEnum_g_tc_members[2]=
                {

                    {
                        (char *)"ON",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        DeviceStatusEnum::ON, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"OFF",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        DeviceStatusEnum::OFF, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DeviceStatusEnum_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceStatusEnum", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        DeviceStatusEnum_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DeviceStatusEnum*/

                if (is_initialized) {
                    return &DeviceStatusEnum_g_tc;
                }

                DeviceStatusEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                DeviceStatusEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DeviceStatusEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

                DeviceStatusEnum_g_tc._data._sampleAccessInfo = sample_access_info();
                DeviceStatusEnum_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DeviceStatusEnum_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo DeviceStatusEnum_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DeviceStatusEnum_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DeviceStatusEnum_g_sampleAccessInfo;
                }

                DeviceStatusEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                DeviceStatusEnum_g_sampleAccessInfo.memberAccessInfos = 
                DeviceStatusEnum_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DeviceStatusEnum);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DeviceStatusEnum_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DeviceStatusEnum_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DeviceStatusEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DeviceStatusEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DeviceStatusEnum >;

                DeviceStatusEnum_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DeviceStatusEnum_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DeviceStatusEnum_g_typePlugin = 
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

                return &DeviceStatusEnum_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< DeviceStatusEnum >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DeviceStatusEnum >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DeviceStatus > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DeviceStatus_g_tc_device_id_string;
                static DDS_TypeCode DeviceStatus_g_tc_information_string;

                static DDS_TypeCode_Member DeviceStatus_g_tc_members[4]=
                {

                    {
                        (char *)"device_id",/* Member name */
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
                        (char *)"device_kind",/* Member name */
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
                    }, 
                    {
                        (char *)"device_status",/* Member name */
                        {
                            2,/* Representation ID */
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
                    }, 
                    {
                        (char *)"information",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode DeviceStatus_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceStatus", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DeviceStatus_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DeviceStatus*/

                if (is_initialized) {
                    return &DeviceStatus_g_tc;
                }

                DeviceStatus_g_tc_device_id_string = initialize_string_typecode(((DEVICE_ID_MAX_LENGTH)));
                DeviceStatus_g_tc_information_string = initialize_string_typecode(((INFORMATION_MAX_LENGTH)));

                DeviceStatus_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DeviceStatus_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DeviceStatus_g_tc_device_id_string;
                DeviceStatus_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< DeviceKindUnion>::get().native();
                DeviceStatus_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< DeviceStatusEnum>::get().native();
                DeviceStatus_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DeviceStatus_g_tc_information_string;

                /* Initialize the values for member annotations. */
                DeviceStatus_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                DeviceStatus_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                DeviceStatus_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DeviceStatus_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

                DeviceStatus_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                DeviceStatus_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                DeviceStatus_g_tc._data._sampleAccessInfo = sample_access_info();
                DeviceStatus_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DeviceStatus_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DeviceStatus *sample;

                static RTIXCdrMemberAccessInfo DeviceStatus_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DeviceStatus_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DeviceStatus_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DeviceStatus);
                if (sample == NULL) {
                    return NULL;
                }

                DeviceStatus_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->device_id() - (char *)sample);

                DeviceStatus_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->device_kind() - (char *)sample);

                DeviceStatus_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->device_status() - (char *)sample);

                DeviceStatus_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->information() - (char *)sample);

                DeviceStatus_g_sampleAccessInfo.memberAccessInfos = 
                DeviceStatus_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DeviceStatus);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DeviceStatus_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DeviceStatus_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DeviceStatus_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DeviceStatus_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DeviceStatus >;

                DeviceStatus_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DeviceStatus_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DeviceStatus_g_typePlugin = 
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

                return &DeviceStatus_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DeviceStatus >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DeviceStatus >::get())));
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
            sample.device_id("");
            sample.proximity(0.0f);
        }

        void topic_type_support< ProximityData >::allocate_sample(ProximityData& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.device_id(),  -1, (DEVICE_ID_MAX_LENGTH));
        }

        void topic_type_support< DeviceKindUnion >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DeviceKindUnionPlugin_new,
                DeviceKindUnionPlugin_delete);
        }

        std::vector<char>& topic_type_support< DeviceKindUnion >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DeviceKindUnion& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DeviceKindUnionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DeviceKindUnionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DeviceKindUnion >::from_cdr_buffer(DeviceKindUnion& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DeviceKindUnionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DeviceKindUnion from cdr buffer");
        }

        void topic_type_support< DeviceKindUnion >::reset_sample(DeviceKindUnion& sample) 
        {
            sample._d() = (DeviceKind::SENSOR);
            sample.this_sensor(SensorKind::TEMPERATURE);
            sample._d() = (DeviceKind::ACTUATOR);
            sample.this_actuator(ActuatorKind::BRAKE);

            sample._d() = DeviceKindUnion::default_discriminator();
        }

        void topic_type_support< DeviceKindUnion >::allocate_sample(DeviceKindUnion& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            sample._d() = (DeviceKind::SENSOR);
            ::rti::topic::allocate_sample(sample.this_sensor(),  -1, -1);
            sample._d() = (DeviceKind::ACTUATOR);
            ::rti::topic::allocate_sample(sample.this_actuator(),  -1, -1);

            sample._d() = DeviceKindUnion::default_discriminator();
        }

        void topic_type_support< DeviceStatus >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DeviceStatusPlugin_new,
                DeviceStatusPlugin_delete);
        }

        std::vector<char>& topic_type_support< DeviceStatus >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DeviceStatus& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DeviceStatusPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DeviceStatusPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DeviceStatus >::from_cdr_buffer(DeviceStatus& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DeviceStatusPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DeviceStatus from cdr buffer");
        }

        void topic_type_support< DeviceStatus >::reset_sample(DeviceStatus& sample) 
        {
            sample.device_id("");
            ::rti::topic::reset_sample(sample.device_kind());
            sample.device_status(DeviceStatusEnum::ON);
            sample.information("");
        }

        void topic_type_support< DeviceStatus >::allocate_sample(DeviceStatus& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.device_id(),  -1, (DEVICE_ID_MAX_LENGTH));
            ::rti::topic::allocate_sample(sample.device_kind(),  -1, -1);
            ::rti::topic::allocate_sample(sample.device_status(),  -1, -1);
            ::rti::topic::allocate_sample(sample.information(),  -1, (INFORMATION_MAX_LENGTH));
        }

    }
}  

