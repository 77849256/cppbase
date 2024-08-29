#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
class student
{
public:
    //构造函数——赋值
    student(int id,const char* name,int age)
    :_id(id)
    ,_name(new char[strlen(name)+1]())
    ,_age(age)
    {
        strcpy(_name,name);
        cout<<"赋值call constructor"<<endl;
    }
    //打印函数——输出
    void print(){
        cout<<"id = "<<_id<<endl;
        cout<<"name = "<<_name<<endl;
        cout<<"age = "<<_age<<endl;
    }
    //拷贝构造函数——复制
    student(const student & rhs)
    :_id(rhs._id)
    ,_name(new char[strlen(rhs._name)+1]())
    ,_age(rhs._age)
    {
        strcpy(_name,rhs._name);
        cout<<"复制call copy construction"<<endl;
    }
    //析构函数——释放堆空间
    ~student(){
        cout<<"销毁call destructor"<<endl;
        if(_name){
            delete[] _name;
            _name = nullptr;
        }
    }
    
private:
    int _id;
    char *_name;
    int _age;
};
int main(int argc,char *argv[])
{
    //赋值
    student s1(1,"chenjin",23);
    s1.print();//输出
    //复制
    student s2(s1);
    s2.print();//输出

    return 0;
}

