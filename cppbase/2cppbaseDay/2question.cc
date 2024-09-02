#include "2question.hh"
//using Myspace::add;
using namespace Myspace;
int main(int argc,char *argv[])
{
    int a = 10,b = 20,c = 30;
    double d = 18.8;
    //add(a,b);//30 call ambigous
    add(d,a);//28.8
    add(a,d);//28.8
    add(a,b,c);//60
    using Myspace::add1;
    add1();//10+20=30;
    add1(100);//100+20=120
    return 0;
}

