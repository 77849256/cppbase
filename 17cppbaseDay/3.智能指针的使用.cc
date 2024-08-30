#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::auto_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::vector;

void test0(){
    int * p = new int(20);
    auto_ptr<int> ap(p);
    cout << p << endl;
    cout << ap.get() << endl;
    cout << *ap << endl;

    auto_ptr<int> ap2 = ap;
    cout <<ap2.get()<<endl;
    cout <<*ap2<<endl;

    //auto_ptr提供的拷贝构造底层是移交管理权的方式
    //此时ap已经交出了管理权，变成了空指针，不能再解引用
    /* cout << *ap << endl; */
}
class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        /* cout << "Point(int,int)" << endl; */
    }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point(){
        /* cout << "~Point()" << endl; */
    }
private:
    int _ix;
    int _iy;
};

void test1(){
    unique_ptr<int> up(new int(10));
    cout << *up << endl;
    cout << up.get() << endl;

    unique_ptr<Point> up2(new Point(2,8));
    (*up2).print();
    up2.reset(new Point(3,7));
    up2->print();

    unique_ptr<Point> up3(new Point(6,5));
    /* unique_ptr<Point> up4 = up3; */
    /* up3 = up2; */

    cout << endl;
    vector<unique_ptr<Point>> vec;
    //push_back的参数需要一个右值属性的unique_ptr
    /* vec.push_back(up2); */

    //vector的元素是利用unique_ptr的移动构造
    //产生的unique_ptr临时对象的副本
    vec.push_back(unique_ptr<Point>(new Point(2,4)));
    vec[0]->print();

    //调用了unique_ptr移动构造
    //unique_ptr<Point> && rhs = std::move(up2)
    //新产生的unique_ptr的副本就是vector的元素
    //副本底层的指针接管up2原本的资源
    //并将rhs底层的指针置空，up2底层的指针也会随之改变（空指针）
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));
    vec[1]->print();
    vec[2]->print();

    up2.reset(new Point(4,8));
    up2->print();
}
void test2(){
    shared_ptr<int> sp(new int(20));
    shared_ptr<int> sp2(sp);
    cout << *sp << endl;
    cout << *sp2 << endl;
    cout << sp.get() << endl;
    cout << sp2.get() << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;

    cout << endl;
    shared_ptr<int> sp3(new int(10));
    sp = sp3;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;

    cout << endl;
    vector<shared_ptr<int>> vec;
    vec.push_back(sp);
    vec.push_back(std::move(sp2));
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    /* cout << *sp2 << endl; */
}
int main(int argc,char *argv[])
{
    test0();
    cout<<"================================"<<endl;
    test1();
    cout<<"================================"<<endl;
    test2();
    return 0;
}

