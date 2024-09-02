#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
void test(){
    vector<int> line = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> multiplytable(9,vector<int>(9));
    
    //填充乘法表
    for(int i = 0;i < 9;++i){
        for(int j = 0;j <= i;++j){
            multiplytable[i][j] = (i + 1)*(j + 1);
        }
    }

    //打印下三角乘法表
    for(int i = 0;i < 9;++i){
        //打印空格以形成三角形的左侧
        /* cout<<string(9 - i,' '); */
        for(int j = 0;j <= i;++j){
            cout<<"\t"<< (i+1)<<"*"<<(j+1)<<"="<<multiplytable[i][j];
        }cout<<endl;
    }
}
int main(int argc,char *argv[])
{
    test();
    return 0;
}

