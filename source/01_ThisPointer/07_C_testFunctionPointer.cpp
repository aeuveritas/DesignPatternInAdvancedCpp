// 07_C_testFunctionPointer.cpp
#include <iostream>
using namespace std;

void foo()
{
    cout << "foo" << endl;

    return;
}

int main()
{
    void (*f1)() = &foo;

    f1();

    return 0;
}