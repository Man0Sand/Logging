//
// Created by man0sand on 17.9.2018.
//

#ifndef LOGGING_CONSOLE_LOG_H
#define LOGGING_CONSOLE_LOG_H

#include "i_log.h"

class ConsoleLog : public I_Log
{
    void write(const std::string& entry) override;
};


#endif //LOGGING_CONSOLE_LOG_H
