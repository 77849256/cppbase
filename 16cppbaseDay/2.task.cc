#include <iostream>
using std::cout;
using std::cin;
using std::endl;
template <class T, int kCapacity = 10>
class Stack
{
public:    
    Stack()    
    : _top(-1)    
    , _data(new T[kCapacity]())    
    {        
        cout << "Stack()" << endl;    
    }    
    ~Stack()
    {        
        if(_data){            
            delete [] _data;            
            _data = nullptr;        
        }        
        cout << "~Stack()" << endl;    
    }    
    bool empty() const;    
    bool full() const;    
    void push(const T &);    
    void pop();    
    T top();
private:    
    int _top;    
    T * _data;
};
bool Stack::empty()const{
    if(_top == -1){
        return true;
    }
    return false;
}
bool Stack::full() const{
    if(_top == kCapacity){
        return true;
    }
    return false;
}    
void push(const T &rhs){
    if(full()){
        cerr << "push failed\n" << endl;
    }
    _top ++;
    _data[_top] = rhs;
}
void pop(){
    if(empty()){
        cerr << "pop failed\n" << endl;
    }
    _top --;
} 



int main(int argc,char *argv[])
{
    
    return 0;
}

