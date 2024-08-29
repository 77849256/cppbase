#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance(){
        pthread_once(&_once,&init_r);
        return _pInstance;
    }
    
    /* void func(){ */
    /*     cout << "hello" << endl; */
    /* } */

    void init(int x,int y){
        _ix = x;
        _iy = y;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
   
private:
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    static void init_r(){
        _pInstance = new Singleton(1,2);
        atexit(destroy);
    }

    Singleton() = default;
    Singleton(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Singleton(int,int)" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static pthread_once_t _once;
};
Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

void test0(){
    Singleton::getInstance()->init(3,4);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(8,9);
    Singleton::getInstance()->print();
    /* Singleton::destroy(); */
    /* Singleton::getInstance()->func(); */
    Singleton::getInstance()->init(8,9);
    Singleton::getInstance()->print();

    /* Singleton::init_r(); */
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */
}

int main(void){
    test0();
    return 0;
}

