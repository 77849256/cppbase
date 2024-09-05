#include <iostream>
#include <algorithm>
#include <set>

using std::cin,std::cout,std::endl;
using std::set;
class Example
{
public:
    void test(){
        int n, m;
        cout<<"Enter count of setA and setB : ";
        cin >> n >> m;
        set<int> setA,setB,unionSet;

        //获取集合A
        cout<<"Enter setA: ";
        for(int i = 0;i < n; ++i){
            int element;
            cin >>element;
            setA.insert(element);
        }
        //获取集合B
        cout<<"Enter setB: ";
        for(int i = 0;i < m; ++i){
            int element;
            cin >>element;
            setB.insert(element);
        }
        //cal_union
        set_union(setA.begin(),setA.end(),setB.begin(),setB.end(),
                  inserter(unionSet,unionSet.begin()));
        //cout<<
        cout<<"unionSet = ";
        for(auto it = unionSet.begin();it!=unionSet.end();++it){
            cout <<*it ;
            if (next(it)!=unionSet.end()){
                cout<<" ";
            }
        }
        cout<<endl;
    }
};

int main(int argc,char *argv[])
{
    Example ex;
    ex.test();
    return 0;
}


