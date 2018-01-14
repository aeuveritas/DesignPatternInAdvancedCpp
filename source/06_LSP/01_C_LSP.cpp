// 01_C_LSP.cpp
#include <iostream>
#include <vector>

using namespace std;

class BaseClass
{
public:
    virtual void foo() = 0;
};

class DerivedClassFirst : public BaseClass
{
public:
    virtual void foo() override
        // override: It checks foo() exists in a base class or not
    {
        cout << "Foo for First derived class" << endl;
    }
};

class DerivedClassSecond : public BaseClass
{
public:
    virtual void foo() override
    {
        cout << "Foo for Second derived class" << endl;
    }
};

int main()
{
    vector<BaseClass*> v;

    v.push_back(new DerivedClassFirst);
    
    v.push_back(new DerivedClassSecond);
    
    for (BaseClass* p : v)
    {
        p->foo();
    }
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_LSP 01_C_LSP.cpp
