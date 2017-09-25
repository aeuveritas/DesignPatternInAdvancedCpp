// 04_C_ConstCast.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass(string _name, int _age)
        : name(_name)
        , age(_age)
    {}

    const string getName()
    {
        return name;
    }

    const int getAge()
    {
        return age;
    }

    void print(string instance)
    {
        cout << instance << " Name: " << name << ", Age: " << age << endl;
    }

private:
    const string name;
    const int age;
};

int main()
{
    BaseClass baseSrc {"AAA", 20};

    const string name = baseSrc.getName();
    const int age = baseSrc.getAge();

    //name = "BBB";
    string* tempName = const_cast<string*>(&name);
    *tempName = "BBB";

    //age = 30;
    int* tempAge = const_cast<int*>(&age);
    *tempAge = 30;

    BaseClass baseDest(*tempName, *tempAge);

    baseSrc.print("Source");
    baseDest.print("Destination");

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 04_C_ConstCast 04_C_ConstCast.cpp
