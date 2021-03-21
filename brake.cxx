#include <algorithm>
#include <iostream>

#include <dds/dds.hpp> 

#include "DataTypeDefinitions.hpp"

int brake_main(int domain_id, int sample_count) {

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
