#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;

class Parent
{
public:
	Parent()
	{ cout << "Parent()" << endl; }
	~Parent()
	{ cout << "~Parent()" << endl; }
	//只需要Child类型的指针，不需要类的完整定义
	weak_ptr<Child> _wpChild;
};

class Child
{
public:
	Child()
	{ cout << "child()" << endl; }
	~Child()
	{ cout << "~child()" << endl; }
	shared_ptr<Parent> _spParent;
};

void test0(){
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    cout << parentPtr.use_count() << endl;
    cout << childPtr.use_count() << endl;

    cout << endl;
    parentPtr->_wpChild = childPtr;
    childPtr->_spParent = parentPtr;
    cout << parentPtr.use_count() << endl;
    cout << childPtr.use_count() << endl;
}

int main(void){
    test0();
    return 0;
}

