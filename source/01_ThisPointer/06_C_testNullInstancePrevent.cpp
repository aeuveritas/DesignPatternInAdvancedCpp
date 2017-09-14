// 06_C_testNullInstancePrevent.cpp
#include <iostream>
using namespace std;

class Sample
{
    int data;

    void fooImpl()               // void foo(Sample* this)
    {
        cout << "foo" << endl;

        return;
    }
public:
    static void foo(Sample* const p)
    {
        if (p == nullptr)
        {
            cout << "Null instance" << endl;
            return;
        }

        return p->fooImpl();
    }
};

int main()
{
    Sample* p = nullptr;        // Assume that creating an instance is failed

    Sample::foo(static_cast<Sample* const>(p));
                                // foo(p); -> foo(nullptr);

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 06_C_testNullInstancePrevent 06_C_testNullInstancePrevent.cpp
