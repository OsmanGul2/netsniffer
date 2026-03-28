#include "parser.h"       // our own header — declares packetHandler
#include <iostream>       // lets us use std::cout to print to terminal
#include <pcap.h>         // packet capture library — pcap_pkthdr, u_char etc
#include <netinet/ip.h>   // gives us the IP header struct (struct ip)
#include <netinet/tcp.h>  // gives us the TCP header struct (struct tcphdr)
#include <netinet/udp.h>  // gives us the UDP header struct (struct udphdr)
#include <arpa/inet.h>    // gives us inet_ntoa() — converts IP to readable string
#include <net/ethernet.h> // gives us the Ethernet header struct (struct ether_header)
int totalPackets = 0;
int totalBytes = 0;

void packetHandler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    totalPackets++;
    totalBytes += header->len;

    std::cout << "\n--- Packet #" << totalPackets << " ---" << std::endl;
    std::cout << "Length: " << header->len << " bytes" << std::endl;

    // ── Ethernet Header ──
    const struct ether_header* eth = (struct ether_header*)packet;
    int etherType = ntohs(eth->ether_type);

    // Only handle IPv4 packets
    if (etherType != ETHERTYPE_IP) {
        std::cout << "Non-IPv4 packet, skipping." << std::endl;
        return;
    }

    // ── IP Header ──
    const struct ip* ipHeader = (struct ip*)(packet + sizeof(struct ether_header));
    std::cout << "Source IP:      " << inet_ntoa(ipHeader->ip_src) << std::endl;
    std::cout << "Destination IP: " << inet_ntoa(ipHeader->ip_dst) << std::endl;

    int ipHeaderLen = ipHeader->ip_hl * 4; // ip_hl is in 4-byte words

    // ── TCP ──
    if (ipHeader->ip_p == IPPROTO_TCP) {
        const struct tcphdr* tcpHeader = (struct tcphdr*)(packet + sizeof(struct ether_header) + ipHeaderLen);
        std::cout << "Protocol:       TCP" << std::endl;
        std::cout << "Source Port:    " << ntohs(tcpHeader->th_sport) << std::endl;
        std::cout << "Dest Port:      " << ntohs(tcpHeader->th_dport) << std::endl;

    // ── UDP ──
    } else if (ipHeader->ip_p == IPPROTO_UDP) {
        const struct udphdr* udpHeader = (struct udphdr*)(packet + sizeof(struct ether_header) + ipHeaderLen);
        std::cout << "Protocol:       UDP" << std::endl;
        std::cout << "Source Port:    " << ntohs(udpHeader->uh_sport) << std::endl;
        std::cout << "Dest Port:      " << ntohs(udpHeader->uh_dport) << std::endl;

    // ── ICMP ──
    } else if (ipHeader->ip_p == IPPROTO_ICMP) {
        std::cout << "Protocol:       ICMP" << std::endl;

    } else {
        std::cout << "Protocol:       Other (" << (int)ipHeader->ip_p << ")" << std::endl;
    }

    // ── Running Stats ──
    std::cout << "Total packets: " << totalPackets << " | Total bytes: " << totalBytes << std::endl;
}
