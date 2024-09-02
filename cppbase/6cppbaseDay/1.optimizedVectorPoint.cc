#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point {
public:
    Point(int x, int y)
    : _ix(x)
    , _iy(y) {
        cout << "Point(int,int)" << endl;
    }
    
    // 复制构造函数
    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy) {
        cout << "Point(const Point & rhs)" << endl;
    }

    // 移动构造函数
    Point(Point&& rhs) noexcept
    : _ix(rhs._ix)
    , _iy(rhs._iy) {
        cout << "Point(Point && rhs)" << endl;
        // 移动后将源对象的资源清空或标记为"已移动"
        rhs._ix = 0;
        rhs._iy = 0;
    }

    Point & operator=(const Point & rhs) {
        cout << "Point & operator=(const Point & rhs)" << endl;
        if (this != &rhs) {
            _ix = rhs._ix;
            _iy = rhs._iy;
        }
        return *this;
    }

    // 移动赋值运算符
    Point& operator=(Point&& rhs) noexcept {
        cout << "Point & operator=(Point && rhs)" << endl;
        if (this != &rhs) {
            _ix = rhs._ix;
            _iy = rhs._iy;
            rhs._ix = 0;
            rhs._iy = 0;
        }
        return *this;
    }

    ~Point() {
        cout << "~Point()" << endl;
    }

    void print() const {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

int main() {
    Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
    
    // 使用std::move来避免复制构造
    vector<Point> dots;
    dots.reserve(5); // 提前预留空间以避免后续的内存重新分配
    dots.push_back(std::move(p1));
    dots.push_back(std::move(p2));
    dots.push_back(std::move(p3));
    dots.push_back(std::move(p4));
    dots.push_back(std::move(p5));

    for (const auto & p : dots) {
        p.print();
    }

    return 0;
}

