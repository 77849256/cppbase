#include "Mylogger.hh"

MyLogger* MyLogger::getInstance()
{
    static MyLogger instance;
    return &instance;
}

//MyLogger::MyLogger()
//{
//    // 初始化日志配置
//    log4cpp::OstreamAppender* console = new log4cpp::OstreamAppender("Console", &std::cout);
//    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
//    layout->setConversionPattern("%d{HH:mm:ss} [%p] %c{1}:%L - %m%n");
//    console->setLayout(layout);
//
//    _category.addAppender(console);
//    _category.setPriority(log4cpp::Priority::DEBUG);
//}
//
//MyLogger::~MyLogger()
//{
//    // 清理资源
//    delete _category.getAppender("Console")->getLayout();
//    delete _category.getAppender("Console");
//}

void MyLogger::info(const char *msg, const char *file, const char *func, int line)
{
    _category.info(_formatMessage(msg, file, func, line));
}

void MyLogger::error(const char *msg, const char *file, const char *func, int line)
{
    _category.error(_formatMessage(msg, file, func, line));
}

void MyLogger::warn(const char *msg, const char *file, const char *func, int line)
{
    _category.warn(_formatMessage(msg, file, func, line));
}

void MyLogger::debug(const char *msg, const char *file, const char *func, int line)
{
    _category.debug(_formatMessage(msg, file, func, line));
}

std::string MyLogger::_formatMessage(const char *msg, const char *file, const char *func, int line)
{
    std::stringstream ss;
    ss << msg << " (in " << file << ":" << func << ":" << line << ")";
    return ss.str();
}__
// 使用宏简化日志记录
void test0()
{
    MyLogger *log = MyLogger::getInstance();

    LOG_INFO(log, "The log is info message");
    LOG_ERROR(log, "The log is error message");
    LOG_WARN(log, "The log is warn message");
    LOG_DEBUG(log, "The log is debug message");
}

void test1()
{
    printf("hello, world\n");

    LOG_INFO(MyLogger::getInstance(), "The log is info message");
    LOG_ERROR(MyLogger::getInstance(), "The log is error message");
    LOG_WARN(MyLogger::getInstance(), "The log is warn message");
    LOG_DEBUG(MyLogger::getInstance(), "The log is debug message");
}
int main(int argc,char** argv){
    test0();
    test1();
    return 0;
}
