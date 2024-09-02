#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class B
{
    int y;
public:
    friend class A;
};
class A
{
    int x;
public:
    A(int a,B &r,int b)//A的构造函数在用a初始化x的同时还会用b初始化传入的B对象y
    {
        x = a;
        r.y = b;
    }
    void Display(B & );
};
void A::Display(B &r)
{
    cout<< x <<" "<<r.y<<endl;
}
int main(int argc,char *argv[])
{
    B Obj2;
    A Obj1(33,Obj2,88);
    Obj1.Display(Obj2);
    return 0;
}

