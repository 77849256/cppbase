#include <iostream>

using std::cout;
using std::cin;
using std::endl;
class Complex
{
public:
    Complex(int x,int y)
    :_real(x)
    ,_image(y){}
    friend Complex operator+(const Complex &lhs,const Complex &rhs);
    friend Complex operator-(const Complex &lhs,const Complex &rhs);
    Complex operator+=(const Complex &r);
    Complex operator-=(const Complex &r);
    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);
    void print(){
        cout<<_real<<"+"<<_image<<"i"<<endl;
    }
private:
    int _real;
    int _image;
};
//友元函数形式重载
Complex operator+(const Complex &lhs,const Complex &rhs)
{
    return Complex(lhs._real+rhs._real,lhs._image+rhs._image);
}
Complex operator-(const Complex &lhs,const Complex &rhs)
{
    return Complex(lhs._real-rhs._real,lhs._image-rhs._image);
}
//成员函数形式重载
Complex Complex::operator+=(const Complex &r){
    return Complex(this->_real+=r._real,this->_image+=r._image);
}
Complex Complex::operator-=(const Complex &r){
    return Complex(this->_real-=r._real,this->_image-=r._image);
}
Complex Complex::operator++(){
    return Complex(++this->_real,++this->_image);
}
Complex Complex::operator++(int){
    return Complex(this->_real++,this->_image++);
}
Complex Complex::operator--(){
    return Complex(--this->_real,--this->_image);
}
Complex Complex::operator--(int){
    return Complex(this->_real--,this->_image--);
}

int main(int argc,char *argv[])
{
    Complex cx1(1,1),cx2(2,2);
    Complex cx3 = cx1 + cx2;
    cx3.print();//3+3i
    Complex cx4 = cx1 - cx2;
    cx4.print();//-1+-1i
    cx2 += cx1;
    cx2.print();//3+3i
    cx2 -= cx1;
    cx2.print();//2+2i
    cx2++;
    cx2.print();//3+3i
    ++cx2;
    cx2.print();//4+4i
    cx2--;
    cx2.print();//3+3i
    --cx2;
    cx2.print();//2+2i
    
    return 0;
}

