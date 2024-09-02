#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

// 结构体定义
struct Record {
    string _word;
    int _frequency;
};

// 词典类定义
class Dictionary {
public:
    // 读取文件并统计词频
    void read(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string word;
        while (file >> word) {
            // 将单词中的非法字符去掉并转换为小写
            word = cleanWord(word);

            if (!word.empty()) {
                _dict[word]++;
            }
        }
        file.close();
    }

    // 将统计结果存储到文件
    void store(const string &filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        // 将unordered_map中的数据转为vector<Record>并排序
        vector<Record> records;
        for (const auto &entry : _dict) {
            records.push_back(Record{entry.first, entry.second});
        }
        
        // 按照单词字典顺序排序
        sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
            return a._word < b._word;
        });//Lambda作为sort的第三个参数

        // 写入文件
        for (const auto &record : records) {
            file << record._word << " " << record._frequency << endl;
        }
        file.close();
    }

private:
    unordered_map<string, int> _dict;

    // 清理单词，去除非法字符并转换为小写
    string cleanWord(const string &word) {
        string cleaned;
        for (char ch : word) {
            if (isalpha(ch)) {
                cleaned += tolower(ch);
            }
        }
        return cleaned;
    }
};

int main() {
    Dictionary dict;
    string inputFilePath = "The_Holy_Bible.txt"; // 输入文件路径
    string outputFilePath = "dict.txt";          // 输出文件路径

    dict.read(inputFilePath);
    dict.store(outputFilePath);

    cout << "Word frequency statistics are stored in " << outputFilePath << endl;
    return 0;
}

