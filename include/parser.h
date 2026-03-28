#pragma once
#include <pcap.h>

// Tracks total packets and bytes captured
extern int totalPackets;
extern int totalBytes;

// Called automatically for every captured packet
void packetHandler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);
