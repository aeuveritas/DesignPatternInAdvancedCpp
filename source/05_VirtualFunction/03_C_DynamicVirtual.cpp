// 03_C_DynamicVirtual.cpp
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
    DerivedClass* p = reinterpret_cast<DerivedClass*>(&b);

    p->foo();           // DerivedClass foo
    p->var();           // BaseClass var
    
    p = static_cast<DerivedClass*>(&b);

    p->foo();           // DerivedClass foo
    p->var();           // BaseClass var
    
    p = dynamic_cast<DerivedClass*>(&b);

    if (p == nullptr)
    {
        cout << "Dynamic_cast failed" << endl;   
        p->foo();    // DerivedClass foo
        p->var();    // Segmentation fault
    }
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 03_C_DynamicVirtual 03_C_DynamicVirtual.cpp
