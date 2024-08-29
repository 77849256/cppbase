#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::istringstream;
struct Record
{
    string _word;
    int _frequency = 1;
};

class Dictionary
{
public:
    void read(const string &filename);
    void store(const string &filename);
private:
    vector<Record> _dict;
};
int isexist(vector<Record> &v,string &word){
    int count = 0;
    for(auto & ele : v){
        if(ele._word == word){
            return count;//返回重复单词记录在字典中的下标
        }
        count++;
    }
    return 0;
}

int isfigure(string &word){
    for(auto & ch : word){
        if((ch > 'a' && ch < 'z')||(ch > 'A' && ch < 'Z')){
            return 1;
        }
    }
        return 0;
}
//read需要将数据从内存读入程序中，所以是用到输入流ifstream
//存入数据结构
void Dictionary::read(const string &filename){
    ifstream ifs(filename);
    if(!ifs){
        cerr<<"ifstream open file failed"<<endl;
        return;
    }
    string line;
    string word;
    //循环按行读取，将一行字符串读进iss中，再进行处理
    while(std::getline(ifs,line)){//ifs-->line
        istringstream iss(line);//line-->iss
                                //循环处理这一行的单词
        while(iss>>word){//循环，每次取一个单词
                         //比较该单词是否出现过，
                         //出现过则直接将其词频+1
                         //未出现过，创建新单词记录，词频初始化为1
            int flag = -1;//flag表示该单词在数组下标的位置，初始化为-1表示不存在
            if((flag = isexist(_dict,word))){//此单词已经存在于词典记录中
                _dict[flag]._frequency++;
            }else{//不存在于词典中，创建新纪录
                Record r;
                r._word = word;
                r._frequency = 1;
                _dict.push_back(r);
            }
        }
    }
    ifs.close();
}

//store是将数据从程序中输出保存至内存中，所以应该用文件输出流ofstream
//存入词典文件
void Dictionary::store(const string &filename){
    //已有数据_dict记录数组，
    ofstream ofs("dict.txt");
    for(auto & ele : _dict){
        ofs << ele._word <<"----->"<< ele._frequency << endl;
    }
    ofs.close();
}

int main(int argc,char *argv[])
{
    //先用read函数将数据从文件流中传入到字符串流中
    string filename("The_Holy_Bible.txt");
    Dictionary dic;
    dic.read(filename);//读入数据结构vector<record>中——文件到字典
    dic.store(filename);//将字典数据结构的内容存入文件中——字典到文件
    return 0;
}
