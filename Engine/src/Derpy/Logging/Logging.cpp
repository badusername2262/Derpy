#include "../../Pch.h"
#include "Logging.h"

std::string format_timestamp()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t time_t = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&time_t);
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    return std::string(timestamp);
}