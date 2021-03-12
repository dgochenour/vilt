This example was generated for architecture x64Linux4gcc7.3.0, using the
data type ProximityData from ProximityDatatype.idl.

To Build this example:
======================
 
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=<Release|Debug> ..
$ make 

To Run this Example:
====================
1) Make sure you are in the directory where the USER_QOS_PROFILES.xml file was
generated (the same directory this README file is in).

2) Run /path/to/your/rti_connext_dds-6.0.1/resource/scripts/rtisetenv_x64Linux4gcc7.3.0.bash
to make sure the Connext libraries are in the path, especially if you opened
a new command prompt window.

3) Run the publishing or subscribing application by typing:
$ ./objs/x64Linux4gcc7.3.0/proximity_sensor <domain_id> <sample_count>
$ ./objs/x64Linux4gcc7.3.0/controller <domain_id> <sample_count>
