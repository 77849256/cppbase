#include <iostream>
#include <set>
#include <cmath>
using std::cin,std::cout,std::endl;
using std::set;
using std::pair;

class Point
{
private:
    double _ix;
    double _iy;

public:
    Point(int x = 0,int y = 0)
        :_ix(x)
         ,_iy(y)
    {
        //cout<<"Point(int ,int )"<<endl;
    }

    void display()const{
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }

    double getDistance()const{
        return hypot(_ix,_iy);
    }

    double get_ix()const{
        return _ix;
    }

    double get_iy()const{
        return _iy;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend bool operator>(const Point& lhs,const Point& rhs);
    friend struct ComparePoint;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix
        << ", " <<rhs._iy
        << ")";

    return os;
}

//因为set有自动排序的功能，所以set可以设置第二个模板参数——排序方式
/*==============================================*/
//第一种方法——模板特化
namespace std{
template<>
    struct greater<Point>{
        bool operator()(const Point& lhs,const Point& rhs){
            cout << "template <> struct greater<Point>" << endl;
            if(lhs.getDistance() > rhs.getDistance()){
                return true;
            }else if(lhs.getDistance() < rhs.getDistance()){
                return false;
            }else{
                if(lhs.get_ix() > rhs.get_ix()){
                    return true;
                }else if(lhs.get_ix() < rhs.get_ix()){
                    return false;
                }else{
                    return lhs.get_iy() > rhs.get_iy();
                }

            }
        }
    };
};

/*==============================================*/

//第二种方式——运算符重载
bool operator>(const Point& lhs,const Point& rhs){
    cout << "bool operator>" << endl;
    if(lhs.getDistance() > rhs.getDistance()){
        return true;
    }else if(lhs.getDistance() < rhs.getDistance()){
        return false;
    }else{
        if(lhs._ix > rhs._ix){
            return true;
        }else if(lhs._ix < rhs._ix){
            return false;
        }else{
            return lhs._iy > rhs._iy;
        }
    }
}

/*==============================================*/

//第三种方式——函数对象
struct ComparePoint
{
    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "struct ComparePoint"<< endl;
        if(lhs.getDistance() > rhs.getDistance()){
            return true;
        }else if(lhs.getDistance() < rhs.getDistance()){
            return false;
        }else{
            if(lhs.get_ix() > rhs.get_ix()){
                return true;
            }else if(lhs.get_ix() < rhs.get_ix()){
                return false;
            }else{
                return lhs.get_iy() > rhs.get_iy();
            }
        }
    }
};
/*==============================================*/

    template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

int main(int argc,char *argv[])
{
    //第一种方法——模板特化
    //  set<Point,std::greater<Point>> s1 = {Point(1,1),Point(2,2),Point(3,3),Point(4,4),Point(5,5)};
    //  cout<<endl<<"s1 = ";
    //   display(s1);
    //第二种方式——运算符重载
    set<Point,std::greater<Point>> s2 = {Point(1,1),Point(2,2),Point(3,3),Point(4,4),Point(5,5)};
    cout<<endl<<"s2 = ";
    display(s2);
    //第三种方式——函数对象
   // set<Point,ComparePoint> s3 = {Point(1,1),Point(2,2),Point(3,3),Point(4,4),Point(5,5)};
   // cout<<endl<<"s3 = ";
   // display(s3);
   // return 0;
}


