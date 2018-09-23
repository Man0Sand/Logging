//
// Created by man0sand on 23.9.2018.
//

#include <gtest/gtest.h>

#include "log_mock.h"

TEST(LoggerTest, TestDifferentLogs)
{
    // construct log mocks
    // construct logger
    // execute logger writing with proper level and ensure log mocks are untouched
    // set mock log 1, write to logger, ensure that done
    // set mock log 2, write to logger, ensure that done
    // set nullptr log, write to logger (should pass if nullptr checking works)
}

TEST(LoggerTest, TestCriticalLogLevel)
{
    // construct a log mock
    // construct logger
    // set mock log
    // write to logger with highest, medium and lowest log level
    // ensure correct behavior after each call
}

TEST(LoggerTest, TestWarningLogLevel)
{
    // construct a log mock
    // construct logger
    // set mock log
    // write to logger with highest, medium and lowest log level
    // ensure correct behavior after each call
}

TEST(LoggerTest, TestDebugLogLevel)
{
    // construct a log mock
    // construct logger
    // set mock log
    // write to logger with highest, medium and lowest log level
    // ensure correct behavior after each call
}

TEST(LoggerTest, TestGettersAndSetters)
{
    // Test getter and setter for each log level
}