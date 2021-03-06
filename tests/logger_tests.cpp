//
// Created by man0sand on 23.9.2018.
//

#include <gtest/gtest.h>

#include "log_mock.h"
#include "logger.h"

TEST(LoggerTest, TestDifferentLogs)
{
    LogMock log_mock_1 = LogMock();
    LogMock log_mock_2 = LogMock();
    Logger& logger = Logger::get_instance();
    logger.set_level(Logger::kCritical);
    logger.set_logger(nullptr);

    logger.write("", Logger::kCritical);
    ASSERT_EQ(0, log_mock_1.get_call_count());
    ASSERT_EQ(0, log_mock_2.get_call_count());

    logger.set_logger(&log_mock_1);
    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock_1.get_call_count());
    ASSERT_EQ(0, log_mock_2.get_call_count());

    logger.set_logger(&log_mock_2);
    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock_1.get_call_count());
    ASSERT_EQ(1, log_mock_2.get_call_count());

    logger.set_logger(nullptr);
    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock_1.get_call_count());
    ASSERT_EQ(1, log_mock_2.get_call_count());
}

TEST(LoggerTest, TestCriticalLogLevel)
{
    LogMock log_mock = LogMock();
    Logger& logger = Logger::get_instance();
    logger.set_level(Logger::kCritical);
    logger.set_logger(nullptr);

    logger.set_logger(&log_mock);
    logger.set_level(Logger::kCritical);

    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock.get_call_count());

    logger.write("", Logger::kWarning);
    ASSERT_EQ(1, log_mock.get_call_count());

    logger.write("", Logger::kDebug);
    ASSERT_EQ(1, log_mock.get_call_count());
}

TEST(LoggerTest, TestWarningLogLevel)
{
    LogMock log_mock = LogMock();
    Logger& logger = Logger::get_instance();
    logger.set_level(Logger::kCritical);
    logger.set_logger(nullptr);

    logger.set_logger(&log_mock);
    logger.set_level(Logger::kWarning);

    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock.get_call_count());

    logger.write("", Logger::kWarning);
    ASSERT_EQ(2, log_mock.get_call_count());

    logger.write("", Logger::kDebug);
    ASSERT_EQ(2, log_mock.get_call_count());
}

TEST(LoggerTest, TestDebugLogLevel)
{
    LogMock log_mock = LogMock();
    Logger& logger = Logger::get_instance();
    logger.set_level(Logger::kCritical);
    logger.set_logger(nullptr);

    logger.set_logger(&log_mock);
    logger.set_level(Logger::kDebug);

    logger.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock.get_call_count());

    logger.write("", Logger::kWarning);
    ASSERT_EQ(2, log_mock.get_call_count());

    logger.write("", Logger::kDebug);
    ASSERT_EQ(3, log_mock.get_call_count());
}

TEST(LoggerTest, TestGettersAndSetters)
{
    Logger& logger = Logger::get_instance();
    logger.set_level(Logger::kCritical);
    logger.set_logger(nullptr);

    ASSERT_EQ(Logger::kCritical, logger.get_level());

    logger.set_level(Logger::kDebug);
    ASSERT_EQ(Logger::kDebug, logger.get_level());

    logger.set_level(Logger::kWarning);
    ASSERT_EQ(Logger::kWarning, logger.get_level());

    logger.set_level(Logger::kError);
    ASSERT_EQ(Logger::kError, logger.get_level());

    logger.set_level(Logger::kInfo);
    ASSERT_EQ(Logger::kInfo, logger.get_level());

    logger.set_level(Logger::kCritical);
    ASSERT_EQ(Logger::kCritical, logger.get_level());
}

TEST(LoggerTest, TestSingleton)
{
    Logger& logger1 = Logger::get_instance();
    logger1.set_level(Logger::kCritical);
    logger1.set_logger(nullptr);

    Logger& logger2 = Logger::get_instance();
    logger2.set_level(Logger::kCritical);
    logger2.set_logger(nullptr);

    LogMock log_mock_1 = LogMock();
    LogMock log_mock_2 = LogMock();

    logger1.set_logger(&log_mock_1);

    logger1.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock_1.get_call_count());
    ASSERT_EQ(0, log_mock_2.get_call_count());

    logger2.set_logger(&log_mock_2);

    logger1.write("", Logger::kCritical);
    ASSERT_EQ(1, log_mock_1.get_call_count());
    ASSERT_EQ(1, log_mock_2.get_call_count());

    logger1.set_logger(&log_mock_1);

    logger2.write("", Logger::kCritical);
    ASSERT_EQ(2, log_mock_1.get_call_count());
    ASSERT_EQ(1, log_mock_2.get_call_count());
}