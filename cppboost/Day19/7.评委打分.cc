#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;
using std::string;
class Person
{
    string _name;
    double _score;
public:
    Person(string name,double score)
    :_name(name)
    ,_score(score){}
    double getScore()const{
        return _score;
    }
    string getName()const{
        return _name;
    }
};
struct CompareByScoreRising{
    bool operator()(const Person& p,const Person& p2)const{
        return p.getScore() < p2.getScore();
    }
};
void test(){
    Person p1("chenjin",100);
    Person p2("ganyu",100);
    Person p3("keli",99);
    Person p4("sanbing",60);
    Person p5("naxida",120);
    vector<Person> vec = {p1,p2,p3,p4,p5};
    
    //遍历vector容器
    for(auto & p : vec){
        cout << p.getName() <<" "<< p.getScore() <<" | ";
    }cout<<endl;

    //存入deque容器中
    deque<Person> deq(vec.begin(),vec.end());
    
    //升序排序
    sort(deq.begin(),deq.end(),CompareByScoreRising());//按升序排列
    deq.pop_back();//去掉最高分
    deq.pop_front();//去掉最低分
    
    double sum = 0;
    double average = 0;
    //deq遍历
    for(auto & p : deq){
        sum += p.getScore();
    }cout<<endl;
    
    //剩余分数累加
    cout << "sum = " << sum << endl;

    //剩余分数求平均
    average = sum / deq.size();
    cout << "average = " << average << endl;

    //输出每个选手的姓名，成绩
    for(auto & p : deq){
        cout << p.getName() <<" "<< p.getScore() <<" | ";
    }cout<<endl;
}

int main(int argc,char *argv[])
{
    test();
    return 0;
}

