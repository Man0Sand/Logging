//
// Created by man0sand on 23.9.2018.
//

#ifndef LOGGING_LOGGER_H
#define LOGGING_LOGGER_H

#include <string>
#include "i_log.h"


class Logger
{
public:
    enum Level
    {
        kCritical = 0,
        kError = 1,
        kWarning = 2,
        kInfo = 3,
        kDebug = 4
    };

    Logger(Logger const&) = delete;

    void operator=(Logger const&) = delete;

    void write(const std::string& entry, Level level);

    void set_level(Level level);

    void set_logger(I_Log* p_log);

    Level get_level();

    static Logger& get_instance();

private:
    Logger();

    Level level_;
    I_Log* p_log_;
};


#endif //LOGGING_LOGGER_H
