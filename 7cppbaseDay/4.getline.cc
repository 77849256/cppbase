#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ifstream;
using std::string;
void checkStatus(const istream &is){
    cout<<"is's goodbit:"<<is.good()<<endl;
    cout<<"is's badbit:"<<is.bad()<<endl;
    cout<<"is's failbit:"<<is.fail()<<endl;
    cout<<"is's eofbit:"<<is.eof()<<endl;
    cout<<endl;
}
void test0(){
    string filename("explicit.cc");
    ifstream ifs(filename);
    checkStatus(ifs);
    string word;
    while(ifs>>word){
        cout<<word<<endl;
    }
    ifs.close();
}
void test1(){
    ifstream ifs;
    ifs.open("explicit.cc");
    string line;
    while(std::getline(ifs,line)){
        cout<<line<<endl;
    }
    ifs.close();
}
int main(int argc,char *argv[])
{
    test1();
    return 0;
}

