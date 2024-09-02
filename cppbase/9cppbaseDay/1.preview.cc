#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class CharArray
{
public:
    CharArray(const char * pstr)
        :_capacity(strlen(pstr)+1)
         ,_data(new char[_capacity]())
    {
        strcpy(_data,pstr);
    }
    ~CharArray(){
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
    }

    //"hello"来创建
    //capacity = 6
    //下标只能取到 4
    /* char & operator[](size_t idx){ */
    /*     if(idx < _capacity - 1){ */
    /*         return _data[idx]; */
    /*     }else{ */
    /*         cout << "out of range" << endl; */
    /*         static char nullchar = '\0'; */
    /*         return nullchar; */
    /*     } */
    /* } */
    const char & operator[](size_t idx) const{
        /* cout<<"const的operator[]"<<endl; */
        /* _capacity = 100; */
        /* _data = new char[10](); */
        /* _data[0] = 'H'; */
        return _data[idx];
    }

    void print() const{
        cout << _data << endl;
    }
private:
    size_t _capacity;
    char * _data;
};
int main(int argc,char *argv[])
{
    string str("helloworld");
    const char *str1 = "helloworld";
    CharArray ca(str1);
    cout<<ca[0]<<endl;
    
    return 0;
}

