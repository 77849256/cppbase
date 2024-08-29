#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Myclass
{
public:
    Myclass(int i = 0)
    {
        cout<<i;
    }
    Myclass(const Myclass &x)
    {
        cout<< 2;
    }
    Myclass &operator=(const Myclass &x)
    {
        cout<<3;
        return *this;
    }
    ~Myclass()
    {
        cout<<4;
    }
};
int main(int argc,char *argv[])
{
    Myclass obj1(1),obj2(2);
    Myclass obj3 = obj1;
    return 0;
}

