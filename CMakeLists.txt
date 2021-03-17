cmake_minimum_required(VERSION 3.1)

project(vilt CXX)

set(TARGET_ARCH x64Linux4gcc7.3.0)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    $ENV{NDDSHOME}/include 
    $ENV{NDDSHOME}/include/ndds 
    $ENV{NDDSHOME}/include/ndds/hpp
)

link_directories($ENV{NDDSHOME}/lib/${TARGET_ARCH})
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m64 -Wall")

if(DEFINED RTI_SHARED_LIB)
    set(SHAREDLIB_SFX "")
else()
    set(SHAREDLIB_SFX "z")
    add_compile_definitions(RTI_STATIC)
endif()
if(${CMAKE_BUILD_TYPE} MATCHES "[Rr]elease")
    set(DEBUG_SFX "")
else()
    set(DEBUG_SFX "d")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g")
endif()

message(${CMAKE_CXX_FLAGS})

add_compile_definitions(RTI_UNIX RTI_LINUX RTI_64BIT)

set(SYSLIBS dl m pthread rt)

set(CONNEXT_PRO_LIBS 
    nddscpp2${SHAREDLIB_SFX}${DEBUG_SFX} 
    nddsc${SHAREDLIB_SFX}${DEBUG_SFX} 
    nddscore${SHAREDLIB_SFX}${DEBUG_SFX}
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${TARGET_ARCH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${TARGET_ARCH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objs/${TARGET_ARCH})

set(IDL_GEN_CXX
    ${CMAKE_CURRENT_SOURCE_DIR}/DataTypeDefinitions.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/DataTypeDefinitionsPlugin.cxx
)
set(IDL_GEN_H
    ${CMAKE_CURRENT_SOURCE_DIR}/DataTypeDefinitions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DataTypeDefinitionsPlugin.hpp
)

add_executable(proximity_sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/proximity_sensor.cxx
    ${IDL_GEN_CXX}
    ${IDL_GEN_H}
)
target_link_libraries(proximity_sensor ${CONNEXT_PRO_LIBS} ${SYSLIBS})

add_executable(controller
    ${CMAKE_CURRENT_SOURCE_DIR}/controller.cxx
    ${IDL_GEN_CXX}
    ${IDL_GEN_H}
)
target_link_libraries(controller ${CONNEXT_PRO_LIBS} ${SYSLIBS})

