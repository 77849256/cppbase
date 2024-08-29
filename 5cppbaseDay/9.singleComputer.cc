#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <string>

class Computer {
public:
    // 获取唯一实例的方法
    static Computer& getInstance(const std::string& brand = "", double price = 0.0) {
        static Computer instance(brand, price);
        return instance;
    }

    // 禁止拷贝构造和赋值操作
    Computer(const Computer&) = delete;
    Computer& operator=(const Computer&) = delete;

    // 获取和设置品牌
    void setBrand(const std::string& brand) { this->brand = brand; }
    std::string getBrand() const { return brand; }

    // 获取和设置价格
    void setPrice(double price) { this->price = price; }
    double getPrice() const { return price; }

    // 打印计算机信息
    void printInfo() const {
        std::cout << "Computer(brand=" << brand << ", price=" << price << ")" << std::endl;
    }

private:
    // 私有构造函数
    Computer(const std::string& brand, double price) : brand(brand), price(price) {}

    // 私有析构函数
    ~Computer() {}

    // 存储品牌和价格信息
    std::string brand;
    double price;
};

int main() {
    // 获取唯一实例
    Computer& computer1 = Computer::getInstance("Dell", 1500.0);
    computer1.printInfo();  // Output: Computer(brand=Dell, price=1500)

    // 尝试修改品牌和价格
    Computer& computer2 = Computer::getInstance();
    computer2.setBrand("HP");
    computer2.setPrice(1200.0);
    computer2.printInfo();  // Output: Computer(brand=HP, price=1200)

    // 验证两个引用是否指向同一个实例
    std::cout << std::boolalpha << (&computer1 == &computer2) << std::endl;  // Output: true

    return 0;
}

