//
// Created by man0sand on 17.9.2018.
//

#ifndef LOGGING_FILE_LOG_H
#define LOGGING_FILE_LOG_H

#include "i_log.h"

class FileLog : public I_Log
{
    void write(const std::string& entry) override;
};


#endif //LOGGING_FILE_LOG_H
