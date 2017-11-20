// 02_C_VirtualSize.cpp
#include <iostream>
using namespace std;

class BaseClass
{
protected:
    int val;

public:
    BaseClass(int _val)
        : val(_val)
    {}

    virtual void setVal(int _val)
    {
        val = _val;
    }

    virtual int getVal()
    {
        return val;
    }
    
    virtual void print()
    {
        cout << "BaseClass val: " << val << endl;
    }
};

class DerivedClass : public BaseClass
{
protected:
    int num;

public:
    DerivedClass(int _val, int _num)
        : BaseClass(_val)
        , num(_num)
    {}

    void setNum(int _num)
    {
        num = _num;
    }

    virtual void print()
    {
        cout << "DerivedClass val: " << val
             << ", num: " << num << endl;
    }
};

int main()
{
    BaseClass b(1);
    cout << sizeof(b) << endl;  // 16
                                // = 4 (for int val)
                                // + 4 (for alignment)
                                // + 8 (for the pointer 
                                //      for virtual function table)

    DerivedClass d(2, 3);
    cout << sizeof(d) << endl;  // 16
                                // = 4 (for int val)
                                // + 4 (for num)
                                // + 8 (for the pointer
                                //      for virtual function table)

    BaseClass* p = &d;
    cout << sizeof(p) << endl;  // 8 (size of pointer)

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 02_C_VirtualSize 02_C_VirtualSize.cpp
