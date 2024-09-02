#ifndef __func_HH__
#define __func_HH__
#include <iostream>
using namespace std;

namespace Myspace
{
int add(int x = 0,int y = 0){
    cout<<"add1:"<<x+y<<endl;
    return x + y;
}
double add(double x = 0.0,int y = 0){
    cout<<"add2:"<<x+y<<endl;
    return x + y;
}
double add(int x = 0,double y = 0.0){
    cout<<"add3:"<<x+y<<endl;
    return x + y;
}
int add(int x,int y = 0,int z = 0){
    cout<<"add4:"<<x+y+z<<endl;
    return x + y + z;
}
int add1(int x = 10,int y = 20){
    cout<< x << "+" << y <<endl;
    return x + y;
}
}//end of namespace Myspace

#endif

