#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void swap(int x,int y){//值传递，发生复制
    int temp = x;
    x = y;
    y = temp;
}
void swap2(int *px,int *py){//地址传递，不复制
    int temp = *px;
    *px = *py;
    *py = temp;
}

//在实参传给swap3时，
//其实就是发生了初始化int &x = a;
//int & y = b;
void swap3(int & x,int & y){
    int temp = x;
    x = y;
    y = temp;
}

void test1(){
    int num = 18;
    //const 引用绑定变量
    //既不能修改指向，也不能通过这个引用改变变量的值
    const int & ref = num;
    //ref = 10;
    num = 10;
    cout<<ref<<endl;
}

//函数不希望通过引用改变变量的值
//可以使用常引用
void func(const int &x){
    /*x = 100*/
    cout<< x <<endl;
}

void test2(){
    int num = 1;
    func(num);
    cout<<num<<endl;
}
int main(int argc,char *argv[])
{
    int a = 10;
    int b = 20;
    int *p1=&a,*p2=&b;
    cout<<"a= "<<a<<' '<<"b= "<<b<<endl;
    //swap(a,b);
    //swap2(p1,p2);
    swap3(a,b);
    cout<<"a= "<<a<<' '<<"b= "<<b<<endl;
    test2();
    return 0;
}

