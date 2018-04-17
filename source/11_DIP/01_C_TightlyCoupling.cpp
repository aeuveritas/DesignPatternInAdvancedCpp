// 01_C_TightlyCoupling.cpp
#include <iostream>
using namespace std;

class Vim
{
public:
    void write(string& code)
    {
        cout << code << endl;
    }
};

class Developer
{
public:
    void writeCode(Vim* p, string code)
    {
        p->write(code);
    }
};

int main()
{
    Developer developer;
    Vim vim;

    developer.writeCode(&vim, "Hello, World!");

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_TightlyCoupling 01_C_TightlyCoupling.cpp
