// 04_C_testCallCheck.cpp
#include <iostream>
using namespace std;

class Sample
{
    int data;

protected:
    int fooImpl()
    {
        cout << "foo" << endl;

        return data;
    }

public:
    int foo()
    {
        return this ? fooImpl() : 0;
    }
};

int main()
{
    Sample* p = new Sample();

    p->foo();

    return 0;
}
// Compile: clang++ -std=c++14 -o 04_C_testCallCheck 04_C_testCallCheck.cpp
