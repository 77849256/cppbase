#include <iostream>

class Base {
protected:
    int protectedVar;
public:
    Base() : protectedVar(10) {}
};

class Derived : protected Base {
public:
    void accessBase() {
        std::cout << "protectedVar = " << protectedVar << std::endl;
    }
};

class MoreDerived : public Derived {
public:
    void accessBase() {
        // 可以访问 protectedVar，因为 Derived 类中 protectedVar 是 protected
        std::cout << "protectedVar in MoreDerived = " << protectedVar << std::endl;
    }
};

int main() {
    MoreDerived md;
    md.accessBase(); // 输出：protectedVar in MoreDerived = 10
    return 0;
}

