#pragma once
#include <string>

// Opens the log file for writing
bool openLog(const std::string& filename);

// Writes a timestamped entry to the log file
void writeLog(const std::string& entry);

// Closes the log file
void closeLog();
