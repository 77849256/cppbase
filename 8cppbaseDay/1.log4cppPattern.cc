#include <iostream>
#include <fstream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using namespace log4cpp;

void test0(){
    //1、创建布局对象
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");
    
    //2、创建目的地对象
    OstreamAppender * appender1 = new OstreamAppender("output",&cout);
    //目的地绑定布局
    appender1->setLayout(ptn1);

    //3、创建记录器
    Category & sub1 = Category::getRoot().getInstance("sub1");

    //4、设置系统优先级
    sub1.setPriority(Priority::WARN);

    //5、记录器添加目的地
    sub1.addAppender(appender1);

    //6、写日志
    sub1.emerg("this is an emerg msg");
    sub1.fatal("this is a fatal msg");
    sub1.alert("this is an alert msg");
    sub1.crit("this is a crit msg");
    sub1.error("this is an error msg");
    sub1.warn("this is a warn msg");
    sub1.notice("this is a notice msg");
    sub1.info("this is an info msg");
    sub1.debug("this is a debug msg");

    //7、关闭资源
    Category::shutdown();
}

void test1(){
    //1、创建布局对象
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");
    
    //2、创建目的地对象
    FileAppender * appender1 = new FileAppender("fileApp","cj.log");
    //目的地绑定布局
    appender1->setLayout(ptn1);

    //3、创建记录器
    Category & sub1 = Category::getRoot().getInstance("sub1");

    //4、设置系统优先级
    sub1.setPriority(Priority::WARN);

    //5、记录器添加目的地
    sub1.addAppender(appender1);

    //6、写日志
    sub1.emerg("this is an emerg msg");
    sub1.fatal("this is a fatal msg");
    sub1.alert("this is an alert msg");
    sub1.crit("this is a crit msg");
    sub1.error("this is an error msg");
    sub1.warn("this is a warn msg");
    sub1.notice("this is a notice msg");
    sub1.info("this is an info msg");
    sub1.debug("this is a debug msg");

    //7、关闭资源
    Category::shutdown();
}
void test2(){
    //1、创建布局对象
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");
    
    //2、创建目的地对象
    auto appender1 = new RollingFileAppender("rolling",
                                             "ROLL.log",
                                            5*1024,
                                            9);
    //目的地绑定布局
    appender1->setLayout(ptn1);

    //3、创建记录器
    Category & sub1 = Category::getRoot().getInstance("sub1");

    //4、设置系统优先级
    sub1.setPriority(Priority::DEBUG);

    //5、记录器添加目的地
    sub1.addAppender(appender1);

    //6、写日志
    int count = 0;
    while(count<30)
    {
    sub1.emerg("this is an emerg msg");
    sub1.fatal("this is a fatal msg");
    sub1.alert("this is an alert msg");
    sub1.crit("this is a crit msg");
    sub1.error("this is an error msg");
    sub1.warn("this is a warn msg");
    sub1.notice("this is a notice msg");
    sub1.info("this is an info msg");
    sub1.debug("this is a debug msg");
    count++;
    }

    //7、关闭资源
    Category::shutdown();
}

int main(int argc,char *argv[])
{
    test0();//将日志信息输出到终端
    test1();//保存到文件
    test2();//保存到回卷文件
    return 0;
}

