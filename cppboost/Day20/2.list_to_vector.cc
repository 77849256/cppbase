#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;

template<class Container>
void print(Container con){
    for(auto it = con.begin();it !=con.end();++it){
        cout<<*it<<" ";
    }cout<<endl;
}
void test(){
    //定义一个list初始化
    list<const char*> lst = {"hello","world","!"};
    print(lst);
    //创建一个空的vector<string>对象
    vector<string> vec;
    //用assign函数赋值
    vec.assign(lst.begin(),lst.end());
    print(vec);

}
int main(int argc,char *argv[])
{
    test();
    return 0;
}

