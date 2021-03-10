

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ProximityDatatype.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef ProximityDatatype_1543506997_hpp
#define ProximityDatatype_1543506997_hpp

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

static const uint32_t SENSOR_ID_MAX_LENGTH = 16;

class NDDSUSERDllExport ProximityData {
  public:
    ProximityData();

    ProximityData(
        const std::string& sensor_id,
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

    std::string& sensor_id() OMG_NOEXCEPT {
        return m_sensor_id_;
    }

    const std::string& sensor_id() const OMG_NOEXCEPT {
        return m_sensor_id_;
    }

    void sensor_id(const std::string& value) {
        m_sensor_id_ = value;
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

    std::string m_sensor_id_;
    float m_proximity_;

};

inline void swap(ProximityData& a, ProximityData& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProximityData& sample);

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

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // ProximityDatatype_1543506997_hpp

