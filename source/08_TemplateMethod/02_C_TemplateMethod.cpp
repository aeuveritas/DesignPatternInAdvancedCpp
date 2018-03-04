// 02_C_TemplateMethod.cpp
#include <iostream>
#include <vector>
using namespace std;

class BaseClass
{
public:
    void foo()
    {
        cout << "Mutex lock" << endl;
        fooImpl();
        cout << "Mutext unlock" << endl;
    }

protected:
    virtual void fooImpl() 
    {
        cout << "Foo for Base class" << endl;
    }
};

class DerivedClassFirst : public BaseClass
{
public:
    virtual void fooImpl() override
    {
        cout << "Foo for First derived class" << endl;
    }
};

class DerivedClassSecond : public BaseClass
{
public:
    virtual void fooImpl() override
    {
        cout << "Foo for Second derived class" << endl;
    }
};

int main()
{
    vector<BaseClass*> v;

    v.push_back(new BaseClass);
    v.push_back(new DerivedClassFirst);
    v.push_back(new DerivedClassSecond);
    
    for(BaseClass* p : v)
    {
        p->foo();
    }
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 02_C_TemplateMethod 02_C_TemplateMethod.cpp

