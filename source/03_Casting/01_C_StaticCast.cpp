// 01_C_StaticCast.cpp
#include <iostream>
using namespace std;

class BaseClass
{
private:
    string name;

public:
    BaseClass(string _name)
        :  name(_name)
    {}

    virtual void printName()
    {
        cout << name <<  endl;
    }
};

class DerivedClass : public BaseClass
{
    int age;
public:
    DerivedClass(string _name, int _age)
        : BaseClass(_name),
          age(_age)
    {}

    void printAge()
    {
        cout << age << endl;
    }
};

int main()
{
    BaseClass* base = new BaseClass("AAA");
    BaseClass* derive1 = new DerivedClass("BBB", 20);

    base->printName();
    derive1->printName();

    //derive1->printAge();      // Compile error
    // baseClass does not have printAge()

    DerivedClass* derive2 = static_cast<DerivedClass*>(derive1);
    derive2->printAge();

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_StaticCast 01_C_StaticCast.cpp
