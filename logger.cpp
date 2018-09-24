//
// Created by man0sand on 23.9.2018.
//

#include "logger.h"

Logger::Logger() :
        level_(kCritical),
        p_log_(nullptr)
{
}

void Logger::write(const std::string& entry, Logger::Level level)
{
    if (level_ < level)
    {
        return;
    }
    if (!p_log_)
    {
        return;
    }

    p_log_->write(entry);
}

void Logger::set_level(Logger::Level level)
{
    level_ = level;
}

Logger::Level Logger::get_level()
{
    return level_;
}

void Logger::set_logger(I_Log* p_log)
{
    p_log_ = p_log;
}

Logger& Logger::get_instance()
{
    static Logger logger;
    return logger;
}
