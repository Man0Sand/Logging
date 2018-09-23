//
// Created by man0sand on 23.9.2018.
//

#ifndef LOGGING_LOG_MOCK_H
#define LOGGING_LOG_MOCK_H

#include "i_log.h"

class LogMock : public I_Log
{
public:
    LogMock() : call_count_(0)
    {}

    void write(const std::string& entry) override
    {
        ++call_count_;
    }

    int get_call_count()
    {
        return call_count_;
    }

private:
    int call_count_;
};

#endif //LOGGING_LOG_MOCK_H
