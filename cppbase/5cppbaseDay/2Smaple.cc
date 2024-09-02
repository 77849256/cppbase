#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Sample
{
public:
    Sample();
    void Display();
private:
    int i;
    static int k;
};
Sample::Sample()
{
    i = 0;
    k++;
}

void Sample::Display()
{
    cout<<"i = "<< i <<",k = "<< k << endl;
}

int Sample::k = 0;
int main(int argc,char *argv[])
{
    Sample a,b;
    a.Display();
    b.Display();

    return 0;
}

