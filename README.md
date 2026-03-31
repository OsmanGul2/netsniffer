# 🛰️ NetSniffer — Real-Time Network Traffic Monitor

> A low-level C/C++ tool for capturing and analyzing live network traffic in real time using raw packet inspection.

!\[Status](https://img.shields.io/badge/status-WIP%20%2F%20prototype-orange)
!\[Language](https://img.shields.io/badge/language-C%2FC%2B%2B-blue)
!\[Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey)
!\[License](https://img.shields.io/badge/license-MIT-green)

\---

## Overview

**NetSniffer** is a real-time network monitoring tool built in C/C++ that captures and inspects live traffic at the packet level. It leverages low-level network interfaces and capture filters to parse raw packets, making it useful for traffic analysis, debugging network behavior, and learning how data moves across a network.

This project is an **active work in progress** — the core packet capture pipeline is functional, with improvements and additional protocol support planned.

\---

##  Features

*  **Live packet capture** from network interfaces in real time
*  **Packet parsing** — extracts and displays header fields from captured frames
*  **Capture filters** — configurable BPF-style filters to target specific traffic
*  **Interface configuration** — supports specifying which network interface to listen on
*  **Debug output** — verbose mode for diagnosing capture and detection issues

\---

## 🚧 Current Status

This is an early prototype. The following is working:



\[x] Raw packet capture on a configurable network interface

\[x] Basic packet parsing (Ethernet, IP headers)

\[x] Capture filter support

\[x] Debugging output for packet detection issues



\### 🔹 v1 — Complete! (current)

- [x] Live packet capture on a configurable network interface
- [x] Ethernet, IP, TCP, UDP, ICMP header parsing
- [x] Source/destination IP and port extraction
- [x] BPF capture filter support
- [x] Running packet count and byte statistics
- [x] Debug output and verbose mode
- [x] Log file output support



\### 🔹 v2 — Planned

\[ ] Deep protocol inspection (HTTP, DNS)

\[ ] PCAP file export

\[ ] Cross-platform support (Windows)



\### 🔹 v3 — Future

\[ ] Anomaly and threat detection

\[ ] Interactive CLI / TUI dashboard

\[ ] Alerting system

```
netsniffer/
├── src/
│   ├── main.cpp          # Entry point
│   ├── capture.cpp       # Packet capture logic
│   ├── parser.cpp        # Packet parsing and dissection
│   └── filter.cpp        # BPF capture filter helpers
├── include/
│   ├── capture.h
│   ├── parser.h
│   └── filter.h
├── Makefile
├── SETUP.md
├── CONTRIBUTING.md
└── README.md
```

> \*\*Note:\*\* Structure may evolve as the project grows.

\---

##  Quick Start

See [SETUP.md](./SETUP.md) for full installation and build instructions.

```bash
# Clone the repo
git clone https://github.com/yourusername/netsniffer.git
cd netsniffer

# Build
make

# Run (requires root/sudo for raw socket access)
sudo ./netsniffer -i eth0
```

\---

## 🔧 Usage

```
Usage: netsniffer \[OPTIONS]

Options:
  -i <interface>    Network interface to capture on (e.g., eth0, wlan0)
  -f <filter>       BPF capture filter expression (e.g., "tcp port 80")
  -v                Verbose / debug output
  -h                Show this help message
```

**Examples:**

```bash
# Capture all traffic on eth0
sudo ./netsniffer -i eth0

# Capture only HTTP traffic with debug output
sudo ./netsniffer -i eth0 -f "tcp port 80" -v

# Capture DNS traffic on wireless interface
sudo ./netsniffer -i wlan0 -f "udp port 53"
```

\---

##  Requirements

* Linux or macOS
* GCC / G++ (C++17 or later)
* `libpcap` development headers (`libpcap-dev` on Debian/Ubuntu)
* Root privileges (required for raw packet capture)

\---

##  Contributing

Contributions, bug reports, and ideas are welcome — especially since this project is still growing! See [CONTRIBUTING.md](./CONTRIBUTING.md) to get started.

\---

##  License

This project is licensed under the [MIT License](./LICENSE).

\---

##  Author

Made by **\Osman Gul** — feel free to reach out or open an issue if you have questions or suggestions.

