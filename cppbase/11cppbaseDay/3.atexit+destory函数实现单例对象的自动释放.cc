#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Singleton
{
public:
    static Singleton *getInstance(){
        if(nullptr == _pInstance){
            atexit(destory);
            _pInstance = new Singleton(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y){
        _ix = x;
        _iy = y;
    }

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

    static void destory(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton &rhs) = delete;
private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;
};
//懒汉式
//Singleton * Singleton::_pInstance = nullptr;
//饿汉式
Singleton * Singleton::_pInstance = Singleton::getInstance();

void test(){
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

