#pragma once
#include <string>
#include <pcap.h>

bool applyFilter(pcap_t* handle, const std::string& filter); 
