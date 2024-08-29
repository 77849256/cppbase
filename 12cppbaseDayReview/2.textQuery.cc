#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class TextQuery {
public:
    // 读取文件并存储内容
    void readFile(const string &filename);
    
    // 查询单词，输出结果
    void query(const string &word);
    
private:
    vector<string> _lines;                    // 存储文件的每一行
    map<string, set<int>> _wordNumbers;       // 记录每个单词在哪些行出现
    map<string, int> _dict;                   // 记录每个单词出现的次数

    // 清理单词，去除标点符号并转换为小写
    string cleanWord(const string &word);
};

void TextQuery::readFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    
    while (getline(file, line)) {
        _lines.push_back(line);  // 将每一行存入 _lines 向量
        istringstream iss(line);
        string word;

        while (iss >> word) {
            word = cleanWord(word);  // 清理单词
            if (!word.empty()) {
                _wordNumbers[word].insert(lineNumber);  // 记录单词所在的行号
                _dict[word]++;  // 记录单词出现的次数
            }
        }

        lineNumber++;
    }
    file.close();
}

void TextQuery::query(const string &word) {
    auto cleanQueryWord = cleanWord(word);  // 清理查询的单词

    if (_dict.find(cleanQueryWord) != _dict.end()) {
        cout << cleanQueryWord << " occurs " << _dict[cleanQueryWord] << " times." << endl;
        for (int lineNum : _wordNumbers[cleanQueryWord]) {
            cout << "(line " << lineNum << ") " << _lines[lineNum - 1] << endl;
        }
    } else {
        cout << cleanQueryWord << " does not occur in the text." << endl;
    }
}

string TextQuery::cleanWord(const string &word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);  // 转换为小写并去除非字母字符
        }
    }
    return cleaned;
}

int main(int argc, char *argv[]) {
    cout<<"Enter a query word:";
    string queryWord;
    cin>>queryWord;
    cout<<endl;

    TextQuery tq;
    tq.readFile("china_daily.txt");  // 读取指定文件
    tq.query(queryWord);  // 查询指定单词

    return 0;
}

