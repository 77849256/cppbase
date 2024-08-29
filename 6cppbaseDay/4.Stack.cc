#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
class Stack
{
public:
    //构造函数初始化栈
    Stack(int size)
    :maxSize(size)
    ,topIndex(-1)
    {
        data = new int[maxSize];//动态分配数组
    }
    //析构函数释放动态分配的内存
    ~Stack(){
        delete[] data;
    }
    bool empty();   //判断栈是否为空
    bool full();    //判断栈是否已满
    void push(int); //元素入栈
    void pop();     //元素出栈
    int top();      //获取栈顶元素
    void print();   //打印栈内元素
private:
    int* data;      //指向动态数组的指针
    int maxSize;        //栈的最大容量
    int topIndex;       //当前栈顶的索引
};

int main(int argc,char *argv[])
{
    Stack st(5);
    if(st.empty()){
        cout<<"st is empty."<<endl;
    }else{
        cout<<"st is not empty."<<endl;
    }
    st.print();
    st.push(1);
    st.push(2);
    cout<<"st.top() = "<<st.top()<<endl;
    st.print();
    st.pop();
    cout<<"st.top() = "<<st.top()<<endl;
    st.print();
    return 0;
}

bool Stack::empty(){
    return topIndex == -1;
}   
bool Stack::full(){
    return topIndex == maxSize - 1;
}
void Stack::push(int value){
    if(full()){
        throw std::overflow_error("Stack overflow: cannot push, stack is full.");
    }
    data[++topIndex] = value; //先移动索引，再存储元素
}
void Stack::pop(){
    if(empty()){
        throw std::underflow_error("Stack underflow: cannot pop, stack is empty.");
    }
    --topIndex; //只需将索引减1即可
}
int Stack::top(){
    if(empty()){
        throw std::underflow_error("Stack is empty: cannot retrieve the top element.");
    }
    return data[topIndex];
}
void Stack::print(){
     if (empty()) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            std::cout << "Stack elements (from bottom to top): ";
            for (int i = 0; i <= topIndex; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
}   
