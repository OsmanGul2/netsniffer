#pragma once
#include <string>
#include <pcap.h>

// Opens a live capture handle on the given interface with an optional BPF filter
pcap_t* openCapture(const std::string& interface, const std::string& filter);

// Starts the packet capture loop
void startCapture(pcap_t* handle, pcap_handler packetHandler);

// Closes and cleans up the capture handle
void closeCapture(pcap_t* handle);
