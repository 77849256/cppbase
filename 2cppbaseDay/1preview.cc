#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void test0(){
    int num = 10;
    int num2 = 20;
    int & ref = num;//声明ref时进行了初始化（绑定）
    //int & ref2; //error
    cout<<num<<endl;
    cout<<ref<<endl;
    cout<<&num<<endl;
    cout<<&ref<<endl;

    ref = 1;
    cout<<num<<endl;

    //定义引用时必须初始化
    //int &ref2;

    //这里是一个赋值操作，并不是更改绑定
    ref = num2;
    cout<< &num2 << endl;
    cout<< &num << endl;
    cout<< &ref << endl;
    cout<< num << endl;
}

void test1(){
    int num = 100;
    int *p = &num;
    cout<<&p<<endl;
    cout<<p<<endl;
    cout<<&num<<endl;

    int & ref = num;
    //引用的底层也是指针实现的（常量指针）
    //但是无法访问创建的指针变量
    //对引用取址获取到的是其绑定的变量的地址
    cout<<&ref<<endl;
    cout<<ref<<endl;
}
int main(int argc,char *argv[])
{
    //定义方式： 类型&ref = 变量；
    int number = 2;
    int &ref = number;
    //test0();
    test1();
}


