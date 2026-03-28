#include "capture.h"
#include <iostream>
#include <pcap.h>

// Opens the network interface for live capture
pcap_t* openCapture(const std::string& interface, const std::string& filter) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the interface for live capture
    // Arguments: interface, snapshot length, promiscuous mode, timeout ms, error buffer
    pcap_t* handle = pcap_open_live(interface.c_str(), 65536, 1, 1000, errbuf);

    if (!handle) {
        std::cerr << "Error opening interface " << interface << ": " << errbuf << std::endl;
        return nullptr;
    }

    // Apply capture filter if one was provided
    if (!filter.empty()) {
        struct bpf_program fp;
        if (pcap_compile(handle, &fp, filter.c_str(), 0, PCAP_NETMASK_UNKNOWN) == -1) {
            std::cerr << "Filter compile error: " << pcap_geterr(handle) << std::endl;
            return nullptr;
        }
        if (pcap_setfilter(handle, &fp) == -1) {
            std::cerr << "Filter apply error: " << pcap_geterr(handle) << std::endl;
            return nullptr;
        }
        pcap_freecode(&fp);
        std::cout << "Filter applied: " << filter << std::endl;
    }

    std::cout << "Capturing on interface: " << interface << std::endl;
    return handle;
}

// Starts the capture loop, calls packetHandler for each packet
void startCapture(pcap_t* handle, pcap_handler packetHandler) {
    // -1 means capture indefinitely until interrupted
    pcap_loop(handle, -1, packetHandler, nullptr);
}

// Cleanly closes the capture handle
void closeCapture(pcap_t* handle) {
    if (handle) {
        pcap_close(handle);
        std::cout << "Capture closed." << std::endl;
    }
}
