# 🔧 Setup & Installation Guide

This guide walks you through setting up **NetSniffer** on your local machine from scratch.

---

## 📋 Prerequisites

Before building, make sure you have the following installed:

| Dependency | Version | Notes |
|---|---|---|
| GCC / G++ | 9+ | C++17 support required |
| `libpcap` | Any recent | Packet capture library |
| `make` | Any | For the Makefile build |
| Root access | — | Required at runtime |

---

## 🐧 Linux Setup (Debian / Ubuntu)

### 1. Install dependencies

```bash
sudo apt update
sudo apt install -y build-essential libpcap-dev
```

### 2. Clone the repository

```bash
git clone https://github.com/yourusername/netsniffer.git
cd netsniffer
```

### 3. Build the project

```bash
make
```

This will compile the source files and produce the `netsniffer` binary in the project root.

### 4. Run

```bash
sudo ./netsniffer -i eth0
```

> ⚠️ **Root privileges are required** because raw socket and packet capture operations need elevated permissions on Linux.

---

## 🍎 macOS Setup

### 1. Install dependencies via Homebrew

```bash
brew install libpcap
```

> `libpcap` is often already present on macOS via Xcode command-line tools, but installing via Homebrew ensures you have the headers needed for compilation.

### 2. Clone the repository

```bash
git clone https://github.com/yourusername/netsniffer.git
cd netsniffer
```

### 3. Build

```bash
make
```

### 4. Run

```bash
sudo ./netsniffer -i en0
```

> On macOS, your primary network interface is typically `en0` (Wi-Fi) or `en1` (Ethernet).

---

## 🔍 Finding Your Network Interface

Not sure which interface to use? Run one of these:

**Linux:**
```bash
ip link show
# or
ifconfig
```

**macOS:**
```bash
ifconfig
# or
networksetup -listallhardwareports
```

Look for an interface that is `UP` and has an IP address assigned — that's the active one to capture on.

---

## 🛠️ Build Options

The `Makefile` supports a few targets:

```bash
make          # Standard build
make clean    # Remove compiled objects and binary
make debug    # Build with debug symbols (-g flag)
```

To manually compile without make:

```bash
g++ -std=c++17 -o netsniffer src/*.cpp -lpcap
```

---

## ⚠️ Troubleshooting

### Permission denied when running
Raw packet capture requires root. Always run with `sudo`:
```bash
sudo ./netsniffer -i eth0
```

### `libpcap` not found during build
Make sure development headers are installed:
```bash
# Debian/Ubuntu
sudo apt install libpcap-dev

# Fedora/RHEL
sudo dnf install libpcap-devel

# macOS
brew install libpcap
```

### No packets captured
- Double-check the interface name with `ip link show` or `ifconfig`
- Make sure the interface is active and has traffic
- Try running without a filter first to verify capture is working
- Use `-v` for verbose debug output

### Compiler errors about C++17 features
Ensure your GCC version is 9 or later:
```bash
g++ --version
```
If outdated, upgrade:
```bash
sudo apt install g++   # usually pulls latest
```

---

## 🧪 Verifying It Works

After running, you should start seeing packet output in your terminal. To generate test traffic, open a second terminal and run:

```bash
ping google.com
```

You should see ICMP packets appear in the sniffer output.

---

## 📬 Still having issues?

Open a [GitHub Issue](https://github.com/yourusername/netsniffer/issues) with:
- Your OS and version
- GCC/G++ version (`g++ --version`)
- The exact error message or output
