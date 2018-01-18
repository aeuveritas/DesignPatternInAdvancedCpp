// 03_N_StaticMember.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    static void foo(int a)
    {
        x = a;  // = this->x = a
                // However, this is not existed in this static function.
        return;
    }
};

int main()
{
    Point::foo(10);

    return 0;
}
// Compile: Not available
