#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
void vectorprint(vector<int> v){
    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }cout<<endl;
}
void test(){
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4,5};
    vector<int> v3 = {1,2,3,4,5};
    vector<int> v4 = {1,2,3,4,5};
    vector<int> v5 = {1,2,3,4,5};
    vector<vector<int>> vv = {v1,v2,v3,v4,v5};

    for(auto it = vv.begin();it!=vv.end();it++){
        vectorprint(*it);
    }cout<<endl;
}
int main(int argc,char *argv[])
{
    test();
    return 0;
}

