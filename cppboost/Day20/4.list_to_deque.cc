#include <iostream>
#include <list>
#include <deque>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::deque;
class Example
{
public:
    //create a list
    list<int> lst = {1,2,3,4,5,6,7,8,9,10};
    //create two deque
    deque<int> deq1;
    deque<int> deq2;
public:
    void test(){
        //if odd ,->deque1
        for(auto it = lst.begin();it != lst.end();++it){
            if(*it % 2 == 1){ //odd
                deq1.push_back(*it);
            }
            else if(*it % 2 == 0){  //even
                deq2.push_back(*it);
            }
        }
    }
};
template<class Container>
   void print(Container con){
       for(auto &elem:con){
           cout<<elem<<" ";
       }cout<<endl;
   }
int main(int argc,char *argv[])
{
    Example ex;
    ex.test();
    cout<<"list:";
    print(ex.lst);
    cout<<endl<<"deq1: ";
    print(ex.deq1);
    cout<<endl<<"deq2: ";
    print(ex.deq2);
    cout<<endl;
    return 0;
}

