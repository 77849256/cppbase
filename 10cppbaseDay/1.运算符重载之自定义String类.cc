#include <iostream>
#include <cstring>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
class String
{
public:
    String()
    :_pstr(new char[1]())
    {}
    String(const char *str)
    :_pstr(new char[strlen(str)+1])
    {
        cout<<"String(char *str)"<<endl;
    }
    String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr)+1])
    {
        cout<<"String(const String &rhs)"<<endl;
    }
    ~String(){
        //delete[] _pstr;
    }
    String &operator=(const String &rhs)
    {
        _pstr = rhs._pstr;
        return *this;
    }
    String &operator=(char *str)
    {
        _pstr = str;
        return *this;
    }

    friend String operator+(const String &lhs, const String &rhs);

    String &operator+=(String &rhs)
    {
        strcat(_pstr,rhs._pstr);
        return *this;
    }
    String &operator+=(const char *str)
    {
        strcat(_pstr,str);
        return *this;
    }
    char &operator[](std::size_t index)
    {
        if(index < strlen(_pstr)){
            return _pstr[index];
        }else{
            cout<<"out of range"<<endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }
    const char &operator[](std::size_t index) const
    {
        if(index < strlen(_pstr)){
            return _pstr[index];
        }else{
            cout<<"out of range"<<endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }

    std::size_t size() const
    {
        return strlen(_pstr);
    }
    const char* c_str() const
    {
        return _pstr;
    }
    void print(){
        for(int i = 0;i < strlen(_pstr);i++){
            cout<<_pstr[i];
        }cout<<endl;
        return;
    }
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
friend String operator+(const String &lhs, const char *str);
friend String operator+(const char *str, const String &rhs);

private:
    char * _pstr;
};
bool operator==(const String &lhs, const String &rhs)
{
    if(lhs._pstr == rhs._pstr){
        return true;
    }else
    {
        return false;
    }
}
bool operator!=(const String &lhs, const String &rhs)
{
    if(lhs._pstr == rhs._pstr){
        return false;
    }else
    {
        return true;
    }
}

bool operator<(const String &lhs, const String &rhs)
{
    if(lhs._pstr < rhs._pstr){
        return true;
    }else{
        return false;
    }
}
bool operator>(const String &lhs, const String &rhs)
{
    if(lhs._pstr > rhs._pstr){
        return true;
    }else{
        return false;
    }
}
bool operator<=(const String &lhs, const String &rhs)
{
    if(lhs._pstr <= rhs._pstr){
        return true;
    }else{
        return false;
    }
}
bool operator>=(const String &lhs, const String &rhs)
{
    if(lhs._pstr >= rhs._pstr){
        return true;
    }else{
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
    while(is>>s._pstr,!is.eof()){
        if(is.bad()){
            cout<<"istream is broken!"<<endl;
            return is;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"重新给我输入，再他妈输错，老子杵你两下"<<endl;
        }else{
            break;
        }
    }
    return is;
}

String operator+(const String &lhs, const String &rhs)
{
    String str;
    strcpy(str._pstr,lhs._pstr);
    strcat(str._pstr,rhs._pstr);
    return str;
}
String operator+(const String &lhs, const char *str)
{
    String s;
    strcpy(s._pstr,lhs._pstr);
    strcat(s._pstr,str);
    return s;
}
String operator+(const char *str, const String &rhs)
{
    String s;
    strcpy(s._pstr,str);
    strcat(s._pstr,rhs._pstr);
    return s;
}

void test0(){
    String str1("chenjin ");
    str1.print();
    String str2("loves ");
    str2.print();
    String str3("Ganyu!");
    str3.print();
    String str;
    str = str1 + str2 + str3;
    str.print();
    String str11(str1);
    if(str1 == str11)
    {
        str1.print();
        cout<<"==";
        str11.print();
        cout<<endl;
    }
    if(str1 != str3){
        str1.print();
        cout<<"!=";
        str3.print();
        cout<<endl;
    }
    String str0;
    cout<<"Enter a string please:";
    cin >> str0;
    str0.print();
}
int main(int argc,char *argv[])
{
    test0();
    return 0;
}

