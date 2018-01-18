// 01_C_Prototype.cpp
#include <iostream>
#include <vector>
using namespace std;

class BaseClass
{
public:
    virtual void foo()
    {
        cout << "Foo for Base class" << endl;
    }

    virtual BaseClass* clone()
    {
        return new BaseClass(*this);
    }
};

class DerivedClassFirst : public BaseClass
{
public:
    virtual void foo() override
    {
        cout << "Foo for First derived class" << endl;
    }

    DerivedClassFirst* clone() override
    {
        return new DerivedClassFirst(*this);
    }
};

class DerivedClassSecond : public BaseClass
{
    virtual void foo() override
    {
        cout << "Foo for Second derived class" << endl;
    }

    DerivedClassSecond* clone() override
    {
        return new DerivedClassSecond(*this);
    }
};

int main()
{
    vector<BaseClass*> v;

    v.push_back(new DerivedClassFirst);
    v.push_back(new DerivedClassSecond);
    
    int size = v.size();
    for(int i = 0; i < size; i++)
    {
        v.push_back(v[i]->clone());
    }
    
    for(BaseClass* p : v)
    {
        p->foo();
    }
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_Prototype 01_C_Prototype.cpp
