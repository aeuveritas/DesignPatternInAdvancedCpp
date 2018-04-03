// 03_C_VirtualDestructor.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass()
    {
        cout << "Resource allocated" << endl;
    }

    ~DerivedClass()
    {
        cout << "Resource released" << endl;
    }
};

int main()
{
    BaseClass* p = new DerivedClass;

    delete p;
}
// Compile: clang++ -std=c++14
//              -o 03_C_VirtualDestructor 03_C_VirtualDestructorvv.cpp
