#include "filter.h"
#include <iostream>
#include <pcap.h>

bool applyFilter(pcap_t* handle, const std::string& filter) {
    struct bpf_program fp;

    if (pcap_compile(handle, &fp, filter.c_str(), 0, PCAP_NETMASK_UNKNOWN) == -1) {
        std::cerr << "Failed to compile filter: " << pcap_geterr(handle) << std::endl;
        return false;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        std::cerr << "Failed to apply filter: " << pcap_geterr(handle) << std::endl;
        return false;
    }

    pcap_freecode(&fp);
    std::cout << "Filter applied: " << filter << std::endl;
    return true;
}
