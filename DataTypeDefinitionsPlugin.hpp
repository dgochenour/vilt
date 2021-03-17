

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DataTypeDefinitions.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DataTypeDefinitionsPlugin_1463588820_h
#define DataTypeDefinitionsPlugin_1463588820_h

#include "DataTypeDefinitions.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct ProximityData
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct ProximityData)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* ProximityData must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct ProximityData.
*/
typedef  class ProximityData ProximityDataKeyHolder;

#define ProximityDataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ProximityDataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ProximityDataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ProximityDataPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ProximityDataPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define ProximityDataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ProximityDataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ProximityData*
ProximityDataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ProximityData*
ProximityDataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ProximityData*
ProximityDataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ProximityDataPluginSupport_copy_data(
    ProximityData *out,
    const ProximityData *in);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_destroy_data_w_params(
    ProximityData *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_destroy_data_ex(
    ProximityData *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_destroy_data(
    ProximityData *sample);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_print_data(
    const ProximityData *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern ProximityData*
ProximityDataPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ProximityData*
ProximityDataPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_destroy_key_ex(
    ProximityDataKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ProximityDataPluginSupport_destroy_key(
    ProximityDataKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ProximityDataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ProximityDataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ProximityDataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ProximityDataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ProximityDataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ProximityData *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ProximityData *out,
    const ProximityData *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ProximityDataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ProximityData *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ProximityData **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ProximityDataPlugin_deserialize_from_cdr_buffer(
    ProximityData *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ProximityDataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ProximityDataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ProximityDataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ProximityDataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ProximityData ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ProximityDataKeyHolder *key, 
    const ProximityData *instance);

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ProximityData *instance, 
    const ProximityDataKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ProximityData *instance,
    RTIEncapsulationId encapsulationId);

NDDSUSERDllExport extern RTIBool 
ProximityDataPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ProximityDataPlugin_new(void);

NDDSUSERDllExport extern void
ProximityDataPlugin_delete(struct PRESTypePlugin *);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
DeviceKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
DeviceKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DeviceKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
DeviceKindPluginSupport_print_data(
    const DeviceKind *sample, const char *desc, int indent_level);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
SensorKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
SensorKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SensorKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
SensorKindPluginSupport_print_data(
    const SensorKind *sample, const char *desc, int indent_level);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
ActuatorKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
ActuatorKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ActuatorKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
ActuatorKindPluginSupport_print_data(
    const ActuatorKind *sample, const char *desc, int indent_level);

#define DeviceKindUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DeviceKindUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DeviceKindUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DeviceKindUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DeviceKindUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DeviceKindUnion*
DeviceKindUnionPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DeviceKindUnion*
DeviceKindUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DeviceKindUnion*
DeviceKindUnionPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DeviceKindUnionPluginSupport_copy_data(
    DeviceKindUnion *out,
    const DeviceKindUnion *in);

NDDSUSERDllExport extern void 
DeviceKindUnionPluginSupport_destroy_data_w_params(
    DeviceKindUnion *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DeviceKindUnionPluginSupport_destroy_data_ex(
    DeviceKindUnion *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DeviceKindUnionPluginSupport_destroy_data(
    DeviceKindUnion *sample);

NDDSUSERDllExport extern void 
DeviceKindUnionPluginSupport_print_data(
    const DeviceKindUnion *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DeviceKindUnionPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DeviceKindUnionPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DeviceKindUnionPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DeviceKindUnionPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DeviceKindUnionPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DeviceKindUnion *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DeviceKindUnionPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DeviceKindUnion *out,
    const DeviceKindUnion *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DeviceKindUnionPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DeviceKindUnion *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DeviceKindUnionPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DeviceKindUnion **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DeviceKindUnionPlugin_deserialize_from_cdr_buffer(
    DeviceKindUnion *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DeviceKindUnionPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DeviceKindUnionPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DeviceKindUnionPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DeviceKindUnionPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DeviceKindUnionPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DeviceKindUnion ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DeviceKindUnionPlugin_new(void);

NDDSUSERDllExport extern void
DeviceKindUnionPlugin_delete(struct PRESTypePlugin *);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
DeviceStatusEnumPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
DeviceStatusEnumPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DeviceStatusEnumPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
DeviceStatusEnumPluginSupport_print_data(
    const DeviceStatusEnum *sample, const char *desc, int indent_level);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct DeviceStatus
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct DeviceStatus)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* DeviceStatus must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct DeviceStatus.
*/
typedef  class DeviceStatus DeviceStatusKeyHolder;

#define DeviceStatusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DeviceStatusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DeviceStatusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DeviceStatusPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define DeviceStatusPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define DeviceStatusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DeviceStatusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DeviceStatus*
DeviceStatusPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DeviceStatus*
DeviceStatusPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DeviceStatus*
DeviceStatusPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPluginSupport_copy_data(
    DeviceStatus *out,
    const DeviceStatus *in);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_destroy_data_w_params(
    DeviceStatus *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_destroy_data_ex(
    DeviceStatus *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_destroy_data(
    DeviceStatus *sample);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_print_data(
    const DeviceStatus *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern DeviceStatus*
DeviceStatusPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DeviceStatus*
DeviceStatusPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_destroy_key_ex(
    DeviceStatusKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DeviceStatusPluginSupport_destroy_key(
    DeviceStatusKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DeviceStatusPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DeviceStatusPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DeviceStatusPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DeviceStatusPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DeviceStatusPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatus *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatus *out,
    const DeviceStatus *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DeviceStatusPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DeviceStatus *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatus **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DeviceStatusPlugin_deserialize_from_cdr_buffer(
    DeviceStatus *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DeviceStatusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DeviceStatusPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DeviceStatusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DeviceStatusPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatus ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatusKeyHolder *key, 
    const DeviceStatus *instance);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    DeviceStatus *instance, 
    const DeviceStatusKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const DeviceStatus *instance,
    RTIEncapsulationId encapsulationId);

NDDSUSERDllExport extern RTIBool 
DeviceStatusPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DeviceStatusPlugin_new(void);

NDDSUSERDllExport extern void
DeviceStatusPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* DataTypeDefinitionsPlugin_1463588820_h */

