#pragma once

#include "TimeUtil.h"
#include <chrono>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

#define LOG(severity, msg) Logger::log(severity, msg, __FILE__, __LINE__)

#define LOG_DEBUG(message) LOG("DEBUG", message)
#define LOG_INFO(message) LOG("INFO", message)
#define LOG_WARN(message) LOG("WARN", message)
#define LOG_ERROR(message) LOG("ERROR", message)

namespace justanlsp
{

class Logger
{
  public:
    static void log(const std::string &severity, const std::string &message, const char *fileName,
                    uint32_t lineNumber)
    {
        std::ofstream logfile("/tmp/log.txt", std::ios::app);

        if (!logfile)
        {
            std::cerr << "Failed to open log file!" << std::endl;
            return;
        }

        putLogMessage(logfile, message, severity, lineNumber, fileName);

        logfile.close();
    }

  private:
    static void putLogMessage(std::ofstream &log, const std::string &message,
                              const std::string severity, uint32_t lineNumber, const char *fileName)
    {
        log << "[";
        TimeUtil::putTime(log, TimeUtil::now());
        log << "] ";

        log << "[";
        log << fileName << ":" << lineNumber;
        log << "]\t";

        log << severity << ":  " << message << std::endl;
    }
};

} // namespace justanlsp
