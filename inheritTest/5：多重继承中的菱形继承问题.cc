#include <iostream>

class Base {
public:
    int value;
    Base() : value(0) {}
    void setValue(int v) { value = v; }
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};

class Final : public Derived1, public Derived2 {
public:
    void show() {
        std::cout << "Value = " << value << std::endl;
    }
};

int main() {
    Final f;
    f.setValue(100);
    f.show(); // 输出：Value = 100
    return 0;
}

