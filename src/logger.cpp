#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
static std::ofstream logFile;

bool openLog(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        return false;
    }
    std::cout << "Logging to: " << filename << std::endl;
    return true;
}

void writeLog(const std::string& entry) {
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // remove trailing newline
        logFile << "[" << dt << "] " << entry << std::endl;
    }
}

void closeLog() {
    if (logFile.is_open()) {
        logFile.close();
        std::cout << "Log file closed." << std::endl;
    }
}
