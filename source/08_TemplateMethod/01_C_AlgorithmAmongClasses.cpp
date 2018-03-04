// 01_C_AlgorithmAmongClasses.cpp
#include <iostream>
#include <vector>
using namespace std;

class BaseClass
{
public:
    virtual void foo()
    {
        cout << "Mutex lock" << endl;
        cout << "Foo for Base class" << endl;
        cout << "Mutex unlock" << endl;
    }
};

class DerivedClassFirst : public BaseClass
{
public:
    virtual void foo()
    {
        cout << "Mutex lock" << endl;
        cout << "Foo for First derived class" << endl;
        cout << "Mutex unlock" << endl;
    }
};

class DerivedClassSecond : public BaseClass
{
public:
    virtual void foo()
    {
        cout << "Mutex lock" << endl;
        cout << "Foo for Second derived class" << endl;
        cout << "Mutex unlock" << endl;
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
//          -o 01_C_AlgorithmAmongClasses 01_C_AlgorithmAmongClasses.cpp

