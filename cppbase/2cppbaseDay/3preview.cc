#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int a = 100;
int func(){
    //func函数返回的是a的一个副本（临时变量）
    return a;//return时发生复制
}
//要注意返回的引用所绑定的变量生命周期要比函数更长
int b = 200;
int &func2(){
    //return 不会复制
    return b;//返回的实际是一个绑定到b的引用
}

void test0(){
    cout<<func()<<endl;
    //func函数返回的实际是一个临时变量
    //生命周期只有函数调用的这一行
    //编译器人为取地址是为了后续使用
    //所以不允许对临时变量取地址
    //&func();
    cout<<&a<<endl;
    cout<<&func2()<<endl;
    cout<<&b<<endl;
}

int &func3(){
    int *p = new int(10);
    return *p;
}

void test1(){
    //func3调用一次就会new一次
    //cout << func3()<<endl;
    //delete &func3();
    //cout<<&func3()<<endl;
    //cout<<&func3()+1+2<<endl;
    int &ref = func3();
    cout<<ref<<endl;
    cout<<&ref<<endl;
    delete &ref;
}
int main(int argc,char *argv[])
{
    test0();
    test1();
    return 0;
}

