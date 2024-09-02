#ifndef MYLOGGER_H
#define MYLOGGER_H

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/PatternLayout.hh>

// 宏定义，用于获取文件名、函数名和行号
#define FILENAME (__FILE__)
#define FUNCTION (__FUNCTION__)
#define LINE (__LINE__)

// 日志宏，用于简化日志记录
#define LOG_INFO(logger, msg) logger->info(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_ERROR(logger, msg) logger->error(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_WARN(logger, msg) logger->warn(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_DEBUG(logger, msg) logger->debug(msg, __FILE__, __FUNCTION__, __LINE__)

class MyLogger
{
public:
    static MyLogger* getInstance();

    void info(const char *msg, const char *file, const char *func, int line);
    void error(const char *msg, const char *file, const char *func, int line);
    void warn(const char *msg, const char *file, const char *func, int line);
    void debug(const char *msg, const char *file, const char *func, int line);

private:
    MyLogger();
    ~MyLogger();

    log4cpp::Category _category;

    std::string _formatMessage(const char *msg, const char *file, const char *func, int line);
};

#endif // MYLOGGER_H
