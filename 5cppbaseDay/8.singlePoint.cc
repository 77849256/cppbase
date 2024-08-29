#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point
{
public:
    static Point * getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    } 
    void print() const{
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
        cout<<"<<<delete heap"<<endl;
    }
private:
    //构造函数私有
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout<<"Point(int,int)"<<endl;
    }
    //析构函数私有——只能生成堆对象，不能生成栈对象
    ~Point(){
        cout<<"~Point()"<<endl;
    }
    //C++11之后可以将成员函数从类中删除
    Point(Point &rhs) = delete;
    Point &operator=(const Point & rhs)=delete;
    int _ix;
    int _iy;
    //定义一个指针保存第一次创建的对象
    static Point *_pInstance;
};
Point * Point::_pInstance = nullptr;

void test1(){
    //单例对象的规范使用
    //避免多个指针拥有单例对象的管理权
    Point::getInstance()->init(19,78);
    Point::getInstance()->print();
    Point::getInstance()->init(76,28);
    Point::getInstance()->print();
    Point::destroy();

    //这种情况，销毁单例对象之后
    //如果多次调用destroy，实际上每次是又创建一个单例对象，
    //并马上销毁，不合理
    /* Point::getInstance()->destroy(); */
    /* Point::getInstance()->destroy(); */
}
int main(int argc,char *argv[])
{
    test1();
    return 0;
}

