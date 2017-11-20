// 04_C_ReinterpretVirtual.cpp
#include <iostream>
using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout << "A foo" << endl;
    }
};

class B
{
public:
    virtual void var()
    {
        cout << "B var" << endl;
    }
    
    virtual void set()
    {
        cout << "A set" << endl;
    }
};

int main()
{
    A a;
    B* p = reinterpret_cast<B*>(&a);

    p->var();       // A foo
    p->set();       // Segmentation fault

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 04_C_ReinterpretVirtual 04_C_ReinterpretVirtual.cpp
