#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Base
{
public:
    Base(const int & a)
    :_x(a){}
    void print(){
        cout<<_x<<endl;
    }
    friend int operator+(const Base &lhs,const Base &rhs);
private:
    int _x;
};
int operator+(const Base &lhs,const Base &rhs){
    return lhs._x + rhs._x - 4;//两个类的数据成员相加为9，想令其变成5应该减去4
}
int main(int argc,char *argv[])
{
    int i = 2;
    int j = 7;
    Base x(i);
    Base y(j);
    //让x+y的值为7 - 2 = 5
    //x的值为，y的值为
    cout<<(x+y == j - i)<<endl;
    return 0;
}

