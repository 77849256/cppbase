#include <iostream>
#include <cstring>

using namespace std;

class CowString {
public:
    CowString(const char *pstr = "")
        : _data(new StringData(pstr)) {}

    CowString(const CowString &rhs)
        : _data(rhs._data) {
        ++_data->_refCount;
    }

    CowString &operator=(const CowString &rhs) {
        if (this != &rhs) {
            if (--_data->_refCount == 0) {
                delete _data;
            }
            _data = rhs._data;
            ++_data->_refCount;
        }
        return *this;
    }

    ~CowString() {
        if (--_data->_refCount == 0) {
            delete _data;
        }
    }

    // 内部类，负责处理读写分离的逻辑
    class CharProxy {
    public:
        CharProxy(CowString &cowStr, size_t idx)
            : _cowStr(cowStr), _idx(idx) {}

        // 重载赋值运算符，用于写操作
        CharProxy &operator=(char c) {
            if (_cowStr._data->_refCount > 1) {
                _cowStr.detach();
            }
            _cowStr._data->_str[_idx] = c;
            return *this;
        }

        // 隐式转换为char，用于读操作
        operator char() const {
            return _cowStr._data->_str[_idx];
        }

    private:
        CowString &_cowStr;
        size_t _idx;
    };

    CharProxy operator[](size_t idx) {
        return CharProxy(*this, idx);
    }

    const char &operator[](size_t idx) const {
        return _data->_str[idx];
    }

    friend ostream &operator<<(ostream &os, const CowString &str) {
        os << str._data->_str;
        return os;
    }

private:
    struct StringData {
        StringData(const char *pstr)
            : _str(new char[strlen(pstr) + 1]()), _refCount(1) {
            strcpy(_str, pstr);
        }

        ~StringData() {
            delete[] _str;
        }

        char *_str;
        size_t _refCount;
    };

    void detach() {
        if (_data->_refCount > 1) {
            --_data->_refCount;
            _data = new StringData(_data->_str);
        }
    }

    StringData *_data;
};

void test0() {
    CowString str1("hello");
    CowString str2 = str1;  // str1 和 str2 共享相同的字符串数据
    CowString str3("world");

    cout << "Before modification:" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;

    str2[0] = 'H';  // 写操作触发复制

    cout << "After modification:" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
}

int main() {
    test0();
    return 0;
}

