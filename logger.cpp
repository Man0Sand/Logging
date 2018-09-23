//
// Created by man0sand on 23.9.2018.
//

#include "logger.h"

Logger::Logger():
level_(kCritical),
p_log_(nullptr)
{
}

void Logger::write(std::string entry, Logger::Level level)
{
    // check that level is lower or equal to the set level

    // check that p_log_ is not nullptr

    // call the log writing function
}

void Logger::set_level(Logger::Level level)
{
    // set level according to the argument
}

Logger::Level Logger::get_level()
{
    // return the level
    return kWarning;
}

void Logger::set_logger(I_Log* log)
{
    // set logger according to the argument
}
