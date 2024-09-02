#include <iostream>
#include <set>
#include <algorithm>
using std::set;
using std::cout;
using std::cin;
using std::endl;

template<class T>
T add(T a,T b){
    return a + b;
}

void printSet(set<int> s){
    set<int>::iterator it = s.begin();
    for(;it != s.end();it++){
        cout << *it << " ";
    }cout << endl;
}

void test0(){
    int num1 = 1,num2 = 2;
    cout << add(num1,num2) << endl;
    double num3 = 1.1,num4 = 2.2;
    cout << add(num3,num4) <<endl;
    set<int> s1 = {2,3,1},s2 = {5,4,6};
    set<int> s;
    std::set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s,s.begin()));
    printSet(s);
}

int main(int argc,char *argv[])
{
    test0();
    return 0;
}

