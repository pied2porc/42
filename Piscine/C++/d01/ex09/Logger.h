#pragma once
#include <string>

using str_t = std::string;

class Logger
{
    str_t   m_fname;

    void  logToConsole(str_t const&);
    void  logToFile(str_t const&);
    str_t makeLogEntry(str_t const&);

public:
    Logger(str_t const&);

    void  log(str_t const&, str_t const&);
};