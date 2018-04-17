// 02_C_LooselyCoupling
#include <iostream>
using namespace std;

class IEditor
{
public:
    virtual void write(string& code) = 0;
    virtual ~IEditor() {}
};

class Developer
{
public:
    void writeCode(IEditor* p, string code)
    {
        p->write(code);
    }
};

class Vim : public IEditor
{
public:
    virtual void write(string& code)
    {
        cout << "Vim: " << code << endl;
    }
};

class Emacs : public IEditor
{
public:
    void write(string& code)
    {
        cout << "Emacs: " << code << endl;
    }
};

int main()
{
    Developer developer;
    Vim vim;
    Emacs emacs;

    developer.writeCode(&vim, "Hello, World!");
    developer.writeCode(&emacs, "Hello, World!");
    
    return 0;
}
// Compile: clang++ -std=c++14
//              -o 02_C_LooselyCoupling 02_C_LooselyCoupling.cpp
