#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

void readConfig(const string &filename){
    ifstream ifs(filename);//创建文件输入流对象并绑定文件
    if(!ifs.good()){        //错误处理
        cout<<"open file fail!"<<endl;
        return;
    }
    string line;
    string key,value;
    while(getline(ifs,line)){
        //字符串输入流相当于缓冲区，缓存了一行的内容
        //之后可以对这一行的内容进行解析
        istringstream iss(line);
        //利用输入流运算符默认以空格为分隔符的效果
        iss>>key>>value;
        cout<<key<<"------->"<<value<<endl;
    }
}

void test0(){
    //编译器会用C风格字符串创建出一个匿名的string对象，作为实参
    readConfig("myserver.conf");
}

int main(int argc,char *argv[])
{
    test0();
    return 0;
}

