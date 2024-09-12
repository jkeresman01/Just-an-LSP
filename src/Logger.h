#pragma once

#include <chrono>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>

#define LOG(severity, msg) Logger::log(severity, msg, __FILE__, __LINE__)

#define LOG_DEBUG(message) LOG("DEBUG", message)
#define LOG_INFO(message)  LOG("INFO",  message)
#define LOG_WARN(message)  LOG("WARN",  message)
#define LOG_ERROR(message) LOG("ERROR", message)

namespace justanlsp
{

class Logger 
{
public:
    static void log(const std::string& severity,
                    const std::string& message,
                    const char* file,
                    uint32_t line) 
    {
        std::ofstream logfile("/home/josip/faks/semestar_2/SPA/test/log.txt", std::ios::app);

        if (!logfile) 
        {
            std::cerr << "Failed to open log file!" << std::endl;
            return;
        }

        auto now = std::chrono::high_resolution_clock::now();
        std::time_t time = std::chrono::high_resolution_clock::to_time_t(now);

        logfile << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << "] ";
        logfile << "[" << file << ":" << line << "]\t" <<  severity << ":  ";
        logfile << message << std::endl;

        logfile.close();
    }
};

} // justanlsp
