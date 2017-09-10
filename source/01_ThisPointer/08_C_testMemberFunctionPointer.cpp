// 08_C_testMemberFunctionPointer.cpp
#include <iostream>
using namespace std;

class Dialog
{
public:
    static void goo()
    {
        cout << "goo" << endl;

        return;
    }

    void hoo()
    {
        cout << "hoo" << endl;

        return;
    }
};

int main()
{
    void (*fs)() = &Dialog::goo;
    fs();

    void (Dialog::*fn)() = &Dialog::hoo;
    Dialog dialog;
    (dialog.*fn)();

    return 0;
}
