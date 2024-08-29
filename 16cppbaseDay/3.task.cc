#include <iostream>
using namespace std;
//基础模板
template<class T>
T add(T x){
    return x;
}
//可变参数模板
template<class T1,class ...Args>
T1 add(T1 x,Args ...args){
    return x + add(args ...);
}
void test0(){
    int result1 = add(1,2,3,4,5);
    double result2 = add(1.1,2.2,3.3,4.4,5.5);
    auto result3 = add(1,2.2,3,4.4,5);
    cout<< "result1: "<< result1 <<endl;
    cout<< "result2: "<< result2 <<endl;
    cout<< "result3: "<< result3 <<endl;
}
int main()
{
    test0();
    return 0;
}

