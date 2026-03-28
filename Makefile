# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include

# Linker flags — links against libpcap
LDFLAGS = -lpcap

# Source and output
SRC = src/main.cpp src/capture.cpp src/parser.cpp src/filter.cpp src/logger.cpp
TARGET = netsniffer

# Default build
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Build with debug symbols
debug: $(SRC)
	$(CXX) $(CXXFLAGS) -g $(SRC) -o $(TARGET) $(LDFLAGS)

# Remove compiled binary
clean:
	rm -f $(TARGET)
