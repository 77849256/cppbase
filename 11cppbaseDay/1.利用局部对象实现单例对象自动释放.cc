#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Singleton
{
public:
    //静态成员函数创建对象
    static Singleton * getInstance(){
        if(nullptr == _pInstance){
            _pInstance = new Singleton(1,2);
        }
        return _pInstance;
    }
    //初始化函数
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
    //静态成员函数回收对象
    /* static void destoy(){ */
    /*     if(_pInstance){ */
    /*         delete _pInstance; */
    /*         _pInstance = nullptr; */
    /*     } */
    /* } */
    void print(){
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
private:
    Singleton() = default;
    Singleton(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout<<"Singleton(int,int)"<<endl;
    }
    ~Singleton(){
        cout<<"~Singleton()"<<endl;
    }
    
    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;
    friend class AutoRelease;
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};
Singleton * Singleton::_pInstance = nullptr;

class AutoRelease
{
public:
    AutoRelease(Singleton * p)
    :_p(p)
    {}

    ~AutoRelease(){
        if(_p){
            delete _p;
            _p = nullptr;
        }
    }
private:
    Singleton * _p;
};
void test(){
    AutoRelease ar(Singleton::getInstance());
    Singleton::getInstance()->init(3,4);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(8,9);
    Singleton::getInstance()->print();
}
int main(int argc,char *argv[])
{
    test();
    return 0;
}

