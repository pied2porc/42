#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

Logger::Logger(str_t const& fname) : m_fname{ fname } {}

void  Logger::logToConsole(str_t const& msg)
{
    std::cout << makeLogEntry(msg);
}

void  Logger::logToFile(str_t const& msg)
{
    std::ofstream ofs(m_fname, std::ofstream::app);
    if (!ofs) {
        std::cerr << "Failed to open " << m_fname << "\n";
        return;
    }
    ofs << makeLogEntry(msg);
}

str_t Logger::makeLogEntry(str_t const& msg)
{
    auto rawtime{ std::time(nullptr) };
    auto tm{ *std::localtime(&rawtime) };

    std::stringstream ss;
    ss << std::put_time(&tm, "[%Y%m%d_%H%M%S] ");
    std::string timestamp{ ss.str() };

    return (timestamp + msg + '\n');
}

void  Logger::log(str_t const& dest, str_t const& msg)
{
    using Logger_mfn = void(Logger::*)(str_t const&);
    typedef struct s_logger {
        str_t const& dest;
        Logger_mfn   mfn_p;
    } t_logger;

    static t_logger loggers[]{
        {"console", &Logger::logToConsole},
        {"file",    &Logger::logToFile}
    };

    for (auto logger : loggers)
        if (logger.dest == dest) {
            (this->*logger.mfn_p)(msg);
            break;
        }
}