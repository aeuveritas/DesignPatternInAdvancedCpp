// 01_C_NormalDestructor.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    ~BaseClass() {};
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
//              -o 01_C_NormalDestructor 01_C_NormalDestructor.cpp
