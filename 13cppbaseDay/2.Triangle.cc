#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//点类
class Point
{
public:
    Point(float x,float y)
    :_x(x)
    ,_y(y)
    {
        cout<<"Point(int,int)"<<endl;
    }
    float _x;
    float _y;
};

//颜色类
class Color
{
public:
    string color;
    Color(string col)
    :color(col)
    {}
};

//直线类
class Line
{
public:
    Line(Point start,Point end)
    :_sp(start)
    ,_ep(end)
    {}
    float length()const{
        return sqrt(pow(_ep._x - _sp._x,2) + pow(_ep._y - _sp._y,2));
    }
    Point _sp;
    Point _ep;
};

//三角形
class Triangle
:public Line,public Color
{
public:
    Triangle(Point start,Point end,float h,string col)
    :Line(start,end),Color(col),height(h){}
    //计算三角形面积
    float area()const{
        return 0.5*length()*height;
    }
    //计算三角形周长 = 两条直角边与斜边之和
    float perimeter()const{
        float hypotenuse = sqrt(pow(length(),2) + pow(height,2));
        return length() + height + hypotenuse;
    }
    //货取颜色
    string getColor()const{
        return color;
    }
    float height;
};
int main(int argc,char *argv[])
{
    Point p1(0,0);
    Point p2(3,0);
    Triangle triangle(p1,p2,4,"red");

    cout << "Triangle color : " << triangle.getColor() << endl;
    cout << "Triangle area : " << triangle.area() << endl;
    cout << "Triangle perimeter : " << triangle.perimeter() << endl;
    
    return 0;
}

