// 05_C_testNullInstance.cpp
#include <iostream>
using namespace std;

class Sample
{
    int data;

public:
    void foo()                  // void foo(Sample* this)
    {
        cout << "foo" << endl;
    }
};

int main()
{
    Sample* p = nullptr;        // Assume that creating an instance is failed

    p->foo();                   // foo(p); -> foo(nullptr);

    return 0;
}
