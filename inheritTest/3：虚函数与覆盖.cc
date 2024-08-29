#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base::show()" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived::show()" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show(); // 输出：Derived::show()
    delete b; // 不要忘了释放内存
    return 0;
}

