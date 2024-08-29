#include <iostream>
using std::cout;
using std::cin;
using std::endl;
template <class T>
T add(T x,T y)
{
    return x + y;
}
#if 0
int add(int x,int y){
    return x + y;
}
double add(double x,double y){
    return x + y;
}
#endif

void test0(){
    cout<<add(1,2)<<endl;
    cout<< add(1.2,3.4)<<endl;
}
int main(int argc,char *argv[])
{
    test0();
    return 0;
}

