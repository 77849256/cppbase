#include <iostream>
#include <string.h> // for strlen, strcpy

class String {
private:
    char* data_;
    size_t size_;

public:
    // 默认构造函数
    String() : data_(nullptr), size_(0) {}

    // 带参构造函数
    String(const char* str) {
        if (str) {
            size_ = strlen(str);
            data_ = new char[size_ + 1];
            strcpy(data_, str);
        } else {
            data_ = nullptr;
            size_ = 0;
        }
    }

    // 拷贝构造函数（深拷贝）
    String(const String& rhs) : size_(rhs.size_) {
        if (rhs.data_) {
            data_ = new char[size_ + 1];
            strcpy(data_, rhs.data_);
        } else {
            data_ = nullptr;
        }
    }

    // 拷贝赋值运算符（深拷贝）
    String& operator=(const String& rhs) {
        if (this == &rhs) {
            return *this; // 处理自赋值
        }

        delete[] data_; // 释放原来的内存

        size_ = rhs.size_;
        if (rhs.data_) {
            data_ = new char[size_ + 1];
            strcpy(data_, rhs.data_);
        } else {
            data_ = nullptr;
        }

        return *this;
    }

    String (String&& rhs)
    :data_(rhs.data_)
    ,size_(rhs.size_)
    {
        rhs.data_ = nullptr;
        rhs.size_ = 0;
    }

    String operator=(String&& rhs){
        if(this == &rhs){
            return *this;
        }
        delete[] data_;

        data_ = rhs.data_;
        size_ = rhs.size_;
    
        rhs.data_ = nullptr;
        rhs.size_ = 0;
        return *this;
    }

    // 析构函数
    ~String() {
        delete[] data_;
    }

    // 打印函数
    void print() const {
        if (data_) {
            std::cout << data_ << std::endl;
        } else {
            std::cout << "(empty)" << std::endl;
        }
    }
};
int main() {
    String s1("Hello");
    String s2("World");

    // 打印原始字符串
    std::cout << "s1: ";
    s1.print();
    std::cout << "s2: ";
    s2.print();

    // 测试移动构造函数
    String s3 = std::move(s1);
    std::cout << "After move construction, s1: ";
    s1.print();
    std::cout << "s3: ";
    s3.print();

    // 测试移动赋值运算符
    s2 = std::move(s3);
    std::cout << "After move assignment, s2: ";
    s2.print();
    std::cout << "s3: ";
    s3.print();

    return 0;
}

