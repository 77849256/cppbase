#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    String &operator=(const String &rhs);
    ~String();
    void print();
    size_t length() const;
    const char * c_str() const;
private:
    char * _pstr;
};

int main(int argc,char *argv[])
{
     String str1;
     str1.print();

     String str2 = "Hello,world";
     String str3("wangdao");

     str2.print();
     str3.print();

     String str4 = str3;
     str4.print();
 
     str4 = str2;
     str4.print();

    return 0;
}

//构造函数，定义一个空字符数组并用char*指向该字符数组
String::String()
:_pstr(new char[1]())
{
    cout<<"String()"<<endl;
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr)+1]())
{
    cout<<"String(const char *pstr)"<<endl;
    strcpy(_pstr,pstr);
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr)+1]())
{
    cout<<"String(const String &rhs)"<<endl;
    strcpy(_pstr,rhs._pstr);
}

String &String::operator=(const String &rhs){
    cout<<"String & operator=(const String &rhs)"<<endl;
    if(this!=&rhs){
        delete[] _pstr;
        _pstr = new char[strlen(rhs._pstr)+1]();
        strcpy(_pstr,rhs._pstr);
    }
    return *this;
}

String::~String(){
    cout<<"~String()"<<endl;
    if(_pstr){
        delete[] _pstr;
        _pstr = nullptr;
    }
}

void String::print(){
    for(int i = 0;i < strlen(_pstr);i++){
        cout<<_pstr[i];
    }cout<<endl;
}

size_t String::length() const{
    return strlen(_pstr);
}

const char * String::c_str() const{
    return this->_pstr;
}

