#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class String {
public:
    // 构造函数
    String(const char *pstr) {
        _size = strlen(pstr);
        if (_size < 16) {
            strcpy(_buffer._local, pstr);
            _capacity = 15;  // _local数组最大容量15（最后一个位置留给'\0'）
        } else {
            _capacity = _size;
            _buffer._pointer = new char[_capacity + 1];  // 动态分配堆内存
            strcpy(_buffer._pointer, pstr);
        }
    }

    // 析构函数
    ~String() {
        if (_size >= 16) {
            delete[] _buffer._pointer;  // 只有在使用堆内存时才需要删除
        }
    }

    // 重载下标运算符
    char &operator[](size_t idx) {
        assert(idx < _size);
        if (_size < 16) {
            return _buffer._local[idx];
        } else {
            return _buffer._pointer[idx];
        }
    }

    // 友元函数：重载输出流运算符
    friend ostream &operator<<(ostream &os, const String &rhs) {
        if (rhs._size < 16) {
            os << rhs._buffer._local;
        } else {
            os << rhs._buffer._pointer;
        }
        return os;
    }

private:
    union Buffer {
        char *_pointer;  // 当字符串长度大于等于16时，使用堆内存
        char _local[16]; // 当字符串长度小于16时，使用栈内存
    };

    size_t _size;      // 字符串长度
    size_t _capacity;  // 容量
    Buffer _buffer;    // 联合体，存储字符串
};

void test0() {
    String str1("hello");
    String str2("hello,world!!!!!");

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    // 测试下标运算符
    str1[0] = 'H';
    str2[7] = 'W';

    cout << "Modified str1: " << str1 << endl;
    cout << "Modified str2: " << str2 << endl;
}

int main() {
    test0();
    return 0;
}

