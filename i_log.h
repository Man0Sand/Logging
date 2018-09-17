//
// Created by man0sand on 17.9.2018.
//

#ifndef LOGGING_I_LOG_H
#define LOGGING_I_LOG_H

#include <string>

class I_Log
{
public:
    virtual void write(const std::string& entry) = 0;
};


#endif //LOGGING_I_LOG_H
