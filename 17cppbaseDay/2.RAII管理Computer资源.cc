#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class Computer
{
public:
    Computer(const char * brand,double price)
    :_brand(new char[strlen(brand)+1]())
    ,_price(price)
    {
        strcpy(_brand,brand);
        cout<< "Computer(const char * brand,double price)" <<endl;
    }

    Computer(const Computer & rhs)
    :_brand(new char[strlen(rhs._brand)+1]())
    ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout<< "Computer(const Computer & rhs)"<<endl;
    }

    Computer & operator=(const Computer & rhs)
    {
        if(this!=&rhs){
            delete[] _brand;
            new char[strlen(rhs._brand)+1]();
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
            cout<<" Computer & operator=(const Computer & rhs)"<<endl;
        }
        return *this;
    }

    ~Computer()
    {
        if(_brand){
            delete[] _brand;
        }
        cout<<"~Computer()"<<endl;
    }

    void print()const{
        cout << "brand: " << _brand << "\tprice:" << _price << endl;
    }
private:
    char * _brand;
    double _price;
};

template <class T>
class RAII
{
public:
    RAII(T* data)
    :_data(data)
    {
        cout<<"RAII(T*)"<<endl;
    }
    ~RAII(){
        cout<<"~RAII()"<<endl;
        if(_data){
            delete _data;
            _data = nullptr;
        }
    }

    T * operator->(){
        return _data;
    }
    T & operator*(){
        return *_data;
    }
    T * get()const{
        return _data;
    }
    void reset(T* data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }
private:
    T* _data;
};

void test0(){
    RAII<Computer> ra(new Computer("apple",20000));
    ra ->print();

    ra.reset(new Computer("huawei",12000));
    (*ra).print();

}
int main(int argc,char *argv[])
{
    test0();
    return 0;
}

