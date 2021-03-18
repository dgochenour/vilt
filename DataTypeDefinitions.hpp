

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DataTypeDefinitions.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DataTypeDefinitions_1463588922_hpp
#define DataTypeDefinitions_1463588922_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const std::string SYSTEM_QOS_LIBRARY_NAME = "System_Library";

static const std::string PARTICIPANT_BASE_QOS_PROFILE_NAME = "ParticipantBase";

static const std::string DATA_QOS_LIBRARY_NAME = "Data_Library";

static const std::string STREAMING_DATA_QOS_PROFILE_NAME = "StreamingData";

static const std::string STATE_DATA_QOS_PROFILE_NAME = "StateData";

static const std::string PROXIMITY_DATA_TOPIC_NAME = "Proximity Data";

static const std::string DEVICE_STATUS_TOPIC_NAME = "Device Status";

static const uint32_t DEVICE_ID_MAX_LENGTH = 16;

static const uint32_t INFORMATION_MAX_LENGTH = 256;

class NDDSUSERDllExport ProximityData {
  public:
    ProximityData();

    ProximityData(
        const std::string& device_id,
        float proximity);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ProximityData (ProximityData&&) = default;
    ProximityData& operator=(ProximityData&&) = default;
    ProximityData& operator=(const ProximityData&) = default;
    ProximityData(const ProximityData&) = default;
    #else
    ProximityData(ProximityData&& other_) OMG_NOEXCEPT;  
    ProximityData& operator=(ProximityData&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& device_id() OMG_NOEXCEPT {
        return m_device_id_;
    }

    const std::string& device_id() const OMG_NOEXCEPT {
        return m_device_id_;
    }

    void device_id(const std::string& value) {
        m_device_id_ = value;
    }

    float& proximity() OMG_NOEXCEPT {
        return m_proximity_;
    }

    const float& proximity() const OMG_NOEXCEPT {
        return m_proximity_;
    }

    void proximity(float value) {
        m_proximity_ = value;
    }

    bool operator == (const ProximityData& other_) const;
    bool operator != (const ProximityData& other_) const;

    void swap(ProximityData& other_) OMG_NOEXCEPT ;

  private:

    std::string m_device_id_;
    float m_proximity_;

};

inline void swap(ProximityData& a, ProximityData& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProximityData& sample);

struct DeviceKind_def {
    enum type {
        SENSOR,      
        ACTUATOR     
    };
    static type get_default(){ return SENSOR;}
};

typedef ::dds::core::safe_enum< DeviceKind_def > DeviceKind;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DeviceKind& sample);
struct SensorKind_def {
    enum type {
        TEMPERATURE,      
        PROXIMITY,      
        PRESSURE     
    };
    static type get_default(){ return TEMPERATURE;}
};

typedef ::dds::core::safe_enum< SensorKind_def > SensorKind;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const SensorKind& sample);
struct ActuatorKind_def {
    enum type {
        BRAKE,      
        THROTTLE,      
        LIGHTS     
    };
    static type get_default(){ return BRAKE;}
};

typedef ::dds::core::safe_enum< ActuatorKind_def > ActuatorKind;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ActuatorKind& sample);

class NDDSUSERDllExport DeviceKindUnion {
  public:
    DeviceKindUnion();

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DeviceKindUnion (DeviceKindUnion&&) = default;
    DeviceKindUnion& operator=(DeviceKindUnion&&) = default;
    DeviceKindUnion& operator=(const DeviceKindUnion&) = default;
    DeviceKindUnion(const DeviceKindUnion&) = default;
    #else
    DeviceKindUnion(DeviceKindUnion&& other_) OMG_NOEXCEPT;  
    DeviceKindUnion& operator=(DeviceKindUnion&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    DeviceKind& _d()  {
        return m_d_;
    }

    const DeviceKind& _d() const  {
        return m_d_;
    }

    void _d(const DeviceKind& value) {
        m_d_ = value;
    }

    SensorKind& this_sensor()  {
        if ( _d() != (DeviceKind::SENSOR)) {
            throw ::dds::core::PreconditionNotMetError(
                "DeviceKindUnion::this_sensor not selected by the discriminator" );
        }
        return m_u_.m_this_sensor_;
    }

    const SensorKind& this_sensor() const  {
        if ( _d() != (DeviceKind::SENSOR)) {
            throw ::dds::core::PreconditionNotMetError(
                "DeviceKindUnion::this_sensor not selected by the discriminator" );
        }
        return m_u_.m_this_sensor_;
    }

    void this_sensor(const SensorKind& value) {
        m_u_.m_this_sensor_ = value;
        m_d_= (DeviceKind::SENSOR);
    }

    ActuatorKind& this_actuator()  {
        if ( _d() != (DeviceKind::ACTUATOR)) {
            throw ::dds::core::PreconditionNotMetError(
                "DeviceKindUnion::this_actuator not selected by the discriminator" );
        }
        return m_u_.m_this_actuator_;
    }

    const ActuatorKind& this_actuator() const  {
        if ( _d() != (DeviceKind::ACTUATOR)) {
            throw ::dds::core::PreconditionNotMetError(
                "DeviceKindUnion::this_actuator not selected by the discriminator" );
        }
        return m_u_.m_this_actuator_;
    }

    void this_actuator(const ActuatorKind& value) {
        m_u_.m_this_actuator_ = value;
        m_d_= (DeviceKind::ACTUATOR);
    }

    bool operator == (const DeviceKindUnion& other_) const;
    bool operator != (const DeviceKindUnion& other_) const;

    static DeviceKind default_discriminator();  

    void swap(DeviceKindUnion& other_) OMG_NOEXCEPT ;

  private:

    DeviceKind m_d_;
    struct NDDSUSERDllExport Union_ {
        SensorKind m_this_sensor_;
        ActuatorKind m_this_actuator_;
        Union_();
        Union_(
            const SensorKind& this_sensor,
            const ActuatorKind& this_actuator);
    };
    Union_ m_u_;

};

inline void swap(DeviceKindUnion& a, DeviceKindUnion& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DeviceKindUnion& sample);

struct DeviceStatusEnum_def {
    enum type {
        ON,      
        OFF     
    };
    static type get_default(){ return ON;}
};

typedef ::dds::core::safe_enum< DeviceStatusEnum_def > DeviceStatusEnum;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DeviceStatusEnum& sample);

class NDDSUSERDllExport DeviceStatus {
  public:
    DeviceStatus();

    DeviceStatus(
        const std::string& device_id,
        const DeviceKindUnion& device_kind,
        const DeviceStatusEnum& device_status,
        const std::string& information);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DeviceStatus (DeviceStatus&&) = default;
    DeviceStatus& operator=(DeviceStatus&&) = default;
    DeviceStatus& operator=(const DeviceStatus&) = default;
    DeviceStatus(const DeviceStatus&) = default;
    #else
    DeviceStatus(DeviceStatus&& other_) OMG_NOEXCEPT;  
    DeviceStatus& operator=(DeviceStatus&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& device_id() OMG_NOEXCEPT {
        return m_device_id_;
    }

    const std::string& device_id() const OMG_NOEXCEPT {
        return m_device_id_;
    }

    void device_id(const std::string& value) {
        m_device_id_ = value;
    }

    DeviceKindUnion& device_kind() OMG_NOEXCEPT {
        return m_device_kind_;
    }

    const DeviceKindUnion& device_kind() const OMG_NOEXCEPT {
        return m_device_kind_;
    }

    void device_kind(const DeviceKindUnion& value) {
        m_device_kind_ = value;
    }

    DeviceStatusEnum& device_status() OMG_NOEXCEPT {
        return m_device_status_;
    }

    const DeviceStatusEnum& device_status() const OMG_NOEXCEPT {
        return m_device_status_;
    }

    void device_status(const DeviceStatusEnum& value) {
        m_device_status_ = value;
    }

    std::string& information() OMG_NOEXCEPT {
        return m_information_;
    }

    const std::string& information() const OMG_NOEXCEPT {
        return m_information_;
    }

    void information(const std::string& value) {
        m_information_ = value;
    }

    bool operator == (const DeviceStatus& other_) const;
    bool operator != (const DeviceStatus& other_) const;

    void swap(DeviceStatus& other_) OMG_NOEXCEPT ;

  private:

    std::string m_device_id_;
    DeviceKindUnion m_device_kind_;
    DeviceStatusEnum m_device_status_;
    std::string m_information_;

};

inline void swap(DeviceStatus& a, DeviceStatus& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DeviceStatus& sample);

class NDDSUSERDllExport BrakeCommand {
  public:
    BrakeCommand();

    BrakeCommand(
        const std::string& device_id,
        float brake_intensity);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    BrakeCommand (BrakeCommand&&) = default;
    BrakeCommand& operator=(BrakeCommand&&) = default;
    BrakeCommand& operator=(const BrakeCommand&) = default;
    BrakeCommand(const BrakeCommand&) = default;
    #else
    BrakeCommand(BrakeCommand&& other_) OMG_NOEXCEPT;  
    BrakeCommand& operator=(BrakeCommand&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& device_id() OMG_NOEXCEPT {
        return m_device_id_;
    }

    const std::string& device_id() const OMG_NOEXCEPT {
        return m_device_id_;
    }

    void device_id(const std::string& value) {
        m_device_id_ = value;
    }

    float& brake_intensity() OMG_NOEXCEPT {
        return m_brake_intensity_;
    }

    const float& brake_intensity() const OMG_NOEXCEPT {
        return m_brake_intensity_;
    }

    void brake_intensity(float value) {
        m_brake_intensity_ = value;
    }

    bool operator == (const BrakeCommand& other_) const;
    bool operator != (const BrakeCommand& other_) const;

    void swap(BrakeCommand& other_) OMG_NOEXCEPT ;

  private:

    std::string m_device_id_;
    float m_brake_intensity_;

};

inline void swap(BrakeCommand& a, BrakeCommand& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BrakeCommand& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ProximityData > {
            NDDSUSERDllExport static std::string value() {
                return "ProximityData";
            }
        };

        template<>
        struct is_topic_type< ProximityData > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ProximityData > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ProximityData& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(ProximityData& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(ProximityData& sample);

            NDDSUSERDllExport 
            static void allocate_sample(ProximityData& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DeviceKindUnion > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceKindUnion";
            }
        };

        template<>
        struct is_topic_type< DeviceKindUnion > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DeviceKindUnion > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DeviceKindUnion& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DeviceKindUnion& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DeviceKindUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DeviceKindUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DeviceStatus > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceStatus";
            }
        };

        template<>
        struct is_topic_type< DeviceStatus > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DeviceStatus > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DeviceStatus& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DeviceStatus& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DeviceStatus& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DeviceStatus& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BrakeCommand > {
            NDDSUSERDllExport static std::string value() {
                return "BrakeCommand";
            }
        };

        template<>
        struct is_topic_type< BrakeCommand > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BrakeCommand > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BrakeCommand& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BrakeCommand& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BrakeCommand& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BrakeCommand& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ProximityData > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< ProximityData > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DeviceKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< DeviceKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< SensorKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< SensorKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ActuatorKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< ActuatorKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DeviceKindUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< DeviceKindUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DeviceStatusEnum > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< DeviceStatusEnum > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DeviceStatus > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DeviceStatus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BrakeCommand > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BrakeCommand > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // DataTypeDefinitions_1463588922_hpp

