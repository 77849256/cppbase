#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
class Point
{
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout<<"Point(int,int)"<<endl;
    }
    Point(const Point & rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout<<"Point(const Point & rhs)"<<endl;
    }
    Point & operator=(const Point & rhs){
        cout<<"Point & operator=(const Point & rhs)"<<endl;
        if(this!=&rhs){
            _ix = rhs._ix;
            _iy = rhs._iy;
        }
        return *this;
    }
    ~Point(){
        cout<<"~Point()"<<endl;
    }
    void print(){
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(int argc,char *argv[])
{
    Point p1(1,1),p2(2,2),p3(3,3),p4(4,4),p5(5,5);
    vector<Point> dots={p1,p2,p3,p4,p5};
    for(auto & p: dots){
        p.print();
    }cout<<endl;
    return 0;
}

