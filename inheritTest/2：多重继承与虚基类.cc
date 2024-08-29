#include <iostream>

class Base1 {
public:
    void show() { std::cout << "Base1::show()" << std::endl; }
};

class Base2 {
public:
    void show() { std::cout << "Base2::show()" << std::endl; }
};

class Derived : public Base1, public Base2 {
public:
    void display() {
        Base1::show(); // 需要指定是哪个基类的show方法
        Base2::show();
    }
};

int main() {
    Derived d;
    d.display();
    return 0;
}

