#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
void test0(){
    ifstream ifs("explicit.cc");
    long pos = ifs.tellg();
    cout<<"pos = "<<pos<<endl;
    
    ifs.seekg(0);
    pos = ifs.tellg();
    cout<<"pos = "<<pos<<endl;

    char *buff = new char[1000]();
    ifs.read(buff,1000);
    cout<<buff<<endl;

    delete[] buff;
    ifs.close();
}

int main(int argc,char *argv[])
{
    test0();
    return 0;
}

