#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

class Student
{
private:
    char* _name;
    int _age;
    double _chinese;
    double _math;
    double _english;
    double _sum;
public:
    //无参构造
    Student()
        :_name(new char[1]())
        ,_age(0)
        ,_chinese(0)
        ,_math(0)
        ,_english(0)
        ,_sum(0)
    {
        cout<<"Student()"<<endl;
        _name[0] = '\0';
    }

    //有参构造
    Student(const char* name,int age,double chinese,double math,double english)
    :_name(new char[strlen(name)+1]())
    ,_age(age)
    ,_chinese(chinese)
    ,_math(math)
    ,_english(english)
    ,_sum(chinese + math + english)
    {
        cout<<"Student(const char*,int,double,double,double)"<<endl;
        strcpy(_name,name);
    }

    //拷贝构造
    Student(const Student & rhs)
    :_name(new char[strlen(rhs._name)+1]())
    ,_age(rhs._age)
    ,_chinese(rhs._chinese)
    ,_math(rhs._math)
    ,_english(rhs._english)
    ,_sum(rhs._chinese + rhs._math + rhs._english)
    {
        cout<<"Student(const Student & rhs)"<<endl;
        strcpy(_name,rhs._name);
    }

    //移动构造
    Student(Student && rhs)
    :_name(rhs._name)
    ,_age(rhs._age)
    ,_chinese(rhs._chinese)
    ,_math(rhs._math)
    ,_english(rhs._english)
    ,_sum(rhs._chinese + rhs._math + rhs._english)
    {
        cout<<"Student(Student && rhs)"<<endl;
        rhs._name = nullptr;
    }

    //赋值运算符函数
    Student & operator=(const Student & rhs){
        cout<<"Student & operator=(const Student & rhs)"<<endl;
        if(this!=&rhs){
            delete[] _name;
            _name = new char[strlen(rhs._name)+1]();
            strcpy(_name,rhs._name);
            _age = rhs._age;
            _chinese = rhs._chinese;
            _math = rhs._math;
            _english = rhs._english;
        }
        return *this;
    }

    //移动赋值运算符函数
    Student & operator=(Student && rhs){
        cout<<"Student & operator=(Student && rhs)"<<endl;
        if(this!=&rhs){
            delete[] _name;
            _name = rhs._name;
            rhs._name = nullptr;
            _age = rhs._age;
            _chinese = rhs._chinese;
            _math = rhs._math;
            _english = rhs._english;
        }
        return *this;
    }
    //析构函数
    ~Student(){
        cout<<"~Student()"<<endl;
        delete[] _name;
    }

    int totalscore(){
        _sum = _chinese + _math + _english;
        return _sum;
    }
    char* getName(){
        return _name;
    }
   friend struct Comparetosumchinese;
};
#if 0
//计算学生总成绩
int totalscore(const Student stu){
    int sum = stu._chinese + stu._math + stu._english;
    return sum;
}
#endif
    struct Comparetosumchinese{
        bool operator()(const Student & stu1,const Student & stu2){
            if(stu1._sum > stu2._sum){
                return true;
            }else if(stu1._sum < stu2._sum){
                return false;
            }else{
                if(stu1._chinese > stu2._chinese){
                    return true;
                }else{
                    return false;
                }
            }
        }

};
int main(int argc,char *argv[])
{
    list<Student> lst = {Student("chenjin",23,100,100,100),
                         Student("ganyu",22,100,100,99),
                         Student("keli",22,99,100,100),
                         Student("sanbing",22,59,59,59),
                         Student("naxida",12,120,100,100)
                         };
    lst.sort(Comparetosumchinese());
    for(auto it = lst.begin();it != lst.end();++it){
        cout<<(*it).getName()<<" ";
    }cout<<endl;
    return 0;
}

