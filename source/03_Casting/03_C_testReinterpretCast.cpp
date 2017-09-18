// 03_C_testReinterpretCast.cpp
#include <iostream>
using namespace std;

class BaseClass
{
public:
    void printClass(string name)
    {
        cout << name << " is BassClass" << endl;
    }
};

int main()
{
    string name = "bastPtr";
    BaseClass* basePtr = new BaseClass{};
    long address = reinterpret_cast<long>(&basePtr);
    cout << "Address is " << address << endl;
    
    basePtr = reinterpret_cast<BaseClass*>(address);
    basePtr->printClass(name);
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 03_C_testReinterpretCast 03_C_testReinterpretCast.cpp
