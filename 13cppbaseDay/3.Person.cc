#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;

class Person
{
public:
    Person(const char* &name,const int & age)
    :_name(new char[strlen(name)+1]())
    ,_age(age)
    {
        cout<<"Person(char*,int)"<<endl;
        strcpy(_name,name);
    }
    ~Person()
    {
        cout<<"~Person()"<<endl;
        delete[] _name;
    }
    Person(const Person &rhs)
    :_name(new char[strlen(rhs._name)+1]())
    ,_age(rhs._age)
    {
        cout<<"Person(char*,int)"<<endl;
        strcpy(_name,rhs._name);
    }
    Person & operator=(const Person &rhs)
    {
        cout<<"赋值运算符函数"<<endl;
        if(this!=&rhs){
            delete []_name;
            _name = new char[strlen(rhs._name)+1]();
            strcpy(_name,rhs._name);
            _age = rhs._age;
        }
        return *this;
    }
    void display()
    {
        cout<<"name: "<<_name<<"\t age:"<<_age<<endl;
    }
    char *_name;
    int _age;
};

class Employee
:public Person
{
    char* _department;
    double _salary;
public:
    Employee(const char* name,int age,const char* department,double salary)
    :Person(name,age)
    ,_department(new char[strlen(department)+1]())
    ,_salary(salary)
    {
        cout<<"Employee(name,age,department,salary)"<<endl;
        strcpy(_department,department);
    }
    ~Employee()
    {
        cout<<"~Employee()"<<endl;
        delete[] _department;
    }
    // 拷贝构造函数
    Employee(const Employee& e)
    : Person(e)
    ,_department(new char[strlen(e._department) + 1]())
    , _salary(e._salary) 
    {
        cout << "Employee(const Employee&)" << endl;
        strcpy(_department, e._department);
    }
    Employee& operator=(const Employee& e){
        if (this == &e) return *this;

        Person::operator=(e); // 调用基类赋值操作符
        delete[] _department; // 释放原来的内存

        _department = new char[strlen(e._department) + 1];
        strcpy(_department, e._department);
        _salary = e._salary;

        return *this;
    }
    void display(){
        Person::display();
        cout<<"Department: "<<_department<<",Salary: "<<_salary<<endl;
    }
        // 静态成员函数：计算平均工资
    static double calculateAverageSalary(Employee* employees, int count) {
        double totalSalary = 0.0;
        for (int i = 0; i < count; ++i) {
            totalSalary += employees[i]._salary;
        }
        return totalSalary / count;
    }
};
int main(int argc,char *argv[])
{
    Employee e1("John", 30, "HR", 5000.0);
    Employee e2("Jane", 25, "Finance", 6000.0);
    Employee e3("Doe", 40, "IT", 7000.0);

    e1.display();
    e2.display();
    e3.display();

    Employee employees[] = { e1, e2, e3 };
    double averageSalary = Employee::calculateAverageSalary(employees, 3);
    std::cout << "Average Salary: " << averageSalary << std::endl;
    return 0;
}

