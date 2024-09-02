#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    Point(int x, int y)
    : _ix(x)
    , _iy(y)
    {}
    friend class Line;
    //将一个普通函数声明为Point类的友元函数
    //那么这个友元函数中可以通过Point对象访问Point类私有的成员
    /* friend */
    /* double distance(const Point & p1,const Point & p2); */
private:
    int _ix;
    int _iy;
};

class Line{
public:
    Line(const Point &start,const Point &end)
    :_start(start),_end(end){}
double distance(const Point & p1,const Point & p2){
    return sqrt(pow(_start._ix - _end._ix,2) + 
                pow(_start._iy - _end._iy,2));
}
    
private:
    Point _start;
    Point _end;
};

void test0(){
    Point pt1(0,0);
    Point pt2(3,4);
    Line l(pt1,pt2);
    cout << l.distance(pt1,pt2) << endl;
}

int main(void){
    test0();
    return 0;
}

