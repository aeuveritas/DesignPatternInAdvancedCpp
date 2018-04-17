// 01_C_PureVirtualFunction.cpp
#include <iostream>
using namespace std;

// Abstract class
class BaseClass
{
public:
    virtual void foo() = 0;    // Pure virtual function
};

// Concrete class
class DerivedClass : public BaseClass
{
public:
	void foo() 
    {
        cout << "Foo" << endl;
    }
};

int main()
{
    // BaseClass b;            // Abstract class cannot be an instance
    DerivedClass d;

    d.foo();
}
// Compile: clang++ -std=c++14
//              -o 01_C_PureVirtualFunction 01_C_PureVirtualFunction.cpp
