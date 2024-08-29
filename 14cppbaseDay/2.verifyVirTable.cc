#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Base{
public:
    virtual void print(){
        cout<<"Base::print()"<<endl;
    }
    virtual void display(){
        cout<<"Base::display()"<<endl;
    }
    virtual void show(){
        cout<<"Base::show()"<<endl;
    }
private:
    long _base = 10;
};
class Derived
:public Base
{
public:
    void print()override{
        cout<<"Derived::print()"<<endl;
    }
    void display()override{
        cout<<"Derived::display()"<<endl;
    }
    void show()override{
        cout<<"Derived::show()"<<endl;
    }
private:
    long _derived = 100;
};
void test0(){
    Derived d;
    printf("pDerived[0]:%p\n",&d);
    //将Derived对象视为long型数组输出
    long *pDerived = reinterpret_cast<long*>(&d);
    cout<<pDerived[0]<<endl;//打印虚表的地址
    cout << pDerived[1] << endl;//打印_base的值=10
	cout << pDerived[2] << endl;//打印_derived的值=100

	cout << endl;
    //将虚表当成long型数组输出
	long * pVtable = reinterpret_cast<long*>(pDerived[0]);//指针指向虚表首地址
	cout << pVtable[0] << endl;//打印虚函数print的入口地址
	cout << pVtable[1] << endl;//打印虚函数display的入口地址
	cout << pVtable[2] << endl;//打印虚函数show的入口地址
    
	cout << endl;
	typedef void (*Function)();
	Function f = (Function)(pVtable[0]);
	f();//打印Detived::print()
	f = (Function)(pVtable[1]);
	f();//打印Detived::display()
	f = (Function)(pVtable[2]);
 	f();//打印Detived::show()
}
int main(int argc,char *argv[])
{
    test0();
    return 0;
}

