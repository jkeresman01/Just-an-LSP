#pragma once

#include "TimeUtil.h"
#include <chrono>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#define LOG(severity) LoggerStream(severity, __FILE__, __LINE__)

#define LOG_DEBUG LOG("DEBUG")
#define LOG_INFO LOG("INFO")
#define LOG_WARN LOG("WARN")
#define LOG_ERROR LOG("ERROR")

namespace justanlsp
{

class Logger
{
  public:
    Logger() = delete;

    static void log(const std::string &severity, const std::string &message, const char *fileName,
                    uint32_t lineNumber)
    {
        std::ofstream logfile("/tmp/log.txt", std::ios::app);

        if (!logfile)
        {
            std::cerr << "No can do for opening log file!" << std::endl;
            return;
        }

        putLogMessage(logfile, message, severity, lineNumber, fileName);

        logfile.close();
    }

  private:
    static void putLogMessage(std::ofstream &log, const std::string &message, const std::string &severity,
                              uint32_t lineNumber, const char *fileName)
    {
        log << "[";
        TimeUtil::putTime(log, TimeUtil::now());
        log << "] ";

        std::ostringstream location;
        location << "[" << fileName << ":" << lineNumber << "]";

        log << location.str();

        int padding = 74 - location.str().length();
        if (padding > 0)
        {
            log << std::setw(padding) << " ";
        }

        log << severity << ": " << message << std::endl;
    }
};

class LoggerStream
{
  public:
    LoggerStream(const std::string &severity, const char *file, uint32_t line)
        : m_severity(severity), m_file(file), m_lineNumber(line), m_stream()
    {
    }

    ~LoggerStream() { Logger::log(m_severity, m_stream.str(), m_file, m_lineNumber); }

    template <typename T> LoggerStream &operator<<(const T &value)
    {
        m_stream << value;
        return *this;
    }

  private:
    std::string m_severity;
    const char *m_file;
    uint32_t m_lineNumber;
    std::ostringstream m_stream;
};

} // namespace justanlsp
