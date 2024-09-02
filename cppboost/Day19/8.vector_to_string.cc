#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
void test(){
    vector<char> vc = {'H','E','L','L','O'};
    string str(vc.begin(),vc.end());
    /* size_t n = vc.size(); */
    /* str.reserve(n); */
    /* for(int i = 0;i < n;++i){ */
    /*     str[i] = vc[i]; */
    /* } */
    cout<< str <<endl;
}
//法二：赋值函数：str.assign(vc.begin(), vc.end());

int main(int argc,char *argv[])
{
    test();
    return 0;
}

