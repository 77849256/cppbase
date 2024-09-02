#include <iostream>

class Base {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    int publicVar;
    Base() : privateVar(1), protectedVar(2), publicVar(3) {}
};

class Derived : private Base {
public:
    void accessMembers() {
        // privateVar 不能访问，编译错误
        // std::cout << "privateVar = " << privateVar << std::endl; // 编译错误
        std::cout << "protectedVar = " << protectedVar << std::endl; // 可以访问
        std::cout << "publicVar = " << publicVar << std::endl; // 可以访问
    }
};

int main() {
    Derived d;
    d.accessMembers();
    // 由于私有继承，Derived类中的成员变量和方法都不能在此处直接访问
    // std::cout << d.publicVar << std::endl; // 编译错误
    return 0;
}

