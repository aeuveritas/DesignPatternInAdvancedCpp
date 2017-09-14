// 01_C_testSimpleExample.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    void set(int a, int b)
    {
        x = a;
        y = b;

        cout << "a: " << a << ", b: " << b << endl;

        return;
    }
};

int main()
{
    Point p1;
    Point p2;

    p1.set(10, 20);
    p2.set(30, 40);

    return 0;
}
// Compile: clang ++ -std=c++14 -o 01_C_testSimpleExample 01_C_testSimpleExample.cpp
