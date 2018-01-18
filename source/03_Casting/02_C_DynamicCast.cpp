// 02_C_DynamicCast.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    virtual void printClass(string name)
    {
        cout << name << " is BassClass" << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    void printClass(string name)
    {
        cout << name << " is DerivedClass" << endl;
    }

    void childMth(string name)
    {
        cout << name << " can call child function" << endl;
    }
};

void printNull(string var)
{
    cout << var << " is null" << endl;
}

int main()
{
    BaseClass base;
    DerivedClass derive;
    BaseClass* _basePtr = &derive;

    string name = "base2DerivePtr";
    DerivedClass* base2DerivePtr = dynamic_cast<DerivedClass*>(&base);
    base2DerivePtr ? base2DerivePtr->printClass(name) : printNull(name);

    name = "basePtr";
    BaseClass* basePtr = dynamic_cast<BaseClass*>(_basePtr);
    basePtr ? basePtr->printClass(name) : printNull(name);
    //basePtr->childMth(name);      // Compile error
    // BaseClass does not have childMth()

    name = "derivePtr";
    DerivedClass* derivePtr = dynamic_cast<DerivedClass*>(_basePtr);
    derivePtr ? derivePtr->printClass(name) : printNull(name);
    derivePtr->childMth(name);

    name = "baseRef";
    BaseClass& baseRef = dynamic_cast<BaseClass&>(*_basePtr);
    baseRef.printClass(name);
    //baseRef.childMth(name);       // Compile error
    // BaseClass does not have childMth()

    name = "deriveRef";
    DerivedClass& deriveRef = dynamic_cast<DerivedClass&>(*_basePtr);
    deriveRef.printClass(name);
    deriveRef.childMth(name);

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 02_C_DynamicCast 02_C_DynamicCast.cpp
