#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::deque;
class Example{
    
public:
    void test(){
        //cin读取一个string序列

        string str;
        cout << "Enter a string : ";
        if(!getline(cin,str)){
            cerr << "getline() failed\n" << endl;
        }

        //存入deque中
        deque<char> deq;
        deq.assign(str.begin(),str.end());
        //打印deque
        for(auto & elem : deq){
            cout << elem;
        }cout << endl;
    }
};
int main(int argc,char *argv[])
{
    Example ex;
    ex.test();
    return 0;
}

