#include <iostream>        // terminal output
#include <string>          // std::string
#include "capture.h"       // openCapture, startCapture, closeCapture
#include "parser.h"        // packetHandler
#include "logger.h"        // openLog, writeLog, closeLog

int main(int argc, char* argv[]) {
    std::string interface = "";
    std::string filter = "";
    std::string logfile = "";
    bool verbose = false;

    // ── Parse command line arguments ──
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-i" && i + 1 < argc) {
            interface = argv[++i];  // network interface e.g. eth0
        } else if (std::string(argv[i]) == "-f" && i + 1 < argc) {
            filter = argv[++i];     // BPF filter e.g. "tcp port 80"
        } else if (std::string(argv[i]) == "-l" && i + 1 < argc) {
            logfile = argv[++i];    // log file path e.g. capture.log
        } else if (std::string(argv[i]) == "-v") {
            verbose = true;         // enable verbose output
        } else if (std::string(argv[i]) == "-h") {
            // print usage and exit
            std::cout << "Usage: netsniffer -i <interface> [-f <filter>] [-l <logfile>] [-v]" << std::endl;
            return 0;
        }
    }

    // ── Validate required arguments ──
    if (interface.empty()) {
        std::cerr << "Error: no interface specified. Use -i <interface>" << std::endl;
        return 1;
    }

    // ── Open log file if specified ──
    if (!logfile.empty()) {
        if (!openLog(logfile)) return 1;
    }

    // ── Open capture handle ──
    pcap_t* handle = openCapture(interface, filter);
    if (!handle) return 1;

    std::cout << "NetSniffer started. Press Ctrl+C to stop." << std::endl;

    // ── Start capture loop ──
    // packetHandler is called automatically for every packet
    startCapture(handle, packetHandler);

    // ── Cleanup ──
    closeCapture(handle);
    closeLog();

    return 0;
}
