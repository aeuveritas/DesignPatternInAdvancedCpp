// 02_C_StaticDestructor.cpp
#include <iostream>
using namespace std;

class BaseClass
{};

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

    delete static_cast<DerivedClass*>(p); 
}
// Compile: clang++ -std=c++14
//              -o 02_C_StaticDestructor 02_C_StaticDestructor.cpp
