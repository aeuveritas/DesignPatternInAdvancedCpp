// 01_C_VirtualFunction.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    void foo()
    {
        cout << "BaseClass foo" << endl;
    }

    virtual void var()
    {
        cout << "BaseClass var" << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    void foo()
    {
        cout << "DerivedClass foo" << endl;
    }

    virtual void var()
    {
        cout << "DerivedClass var" << endl;
    }
};

int main()
{
    BaseClass b;
    DerivedClass d;
    BaseClass* p = &d;

    b.foo();        // BaseClass foo
    d.foo();        // DerivedClass foo
    p->foo();       // BaseClass foo
    
    b.var();        // BaseClass var
    d.var();        // DerivedClass var
    p->var();       // DerivedClass var

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_VirtualFunction 01_C_VirtualFunction.cpp
