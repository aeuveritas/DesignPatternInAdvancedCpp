// 02_C_StackByComposition.cpp
#include <iostream>
#include <vector>
#include <deque>

#include <algorithm>                    // For for_each
using namespace std;

template <typename T1, typename T2=deque<T1>>
class Stack
{
    T2 container;
    
public:
    inline void push(const T1& a)
    {
        container.push_back(a);
    }
    
    inline void pop()
    {
        container.pop_back();
    }
    
    inline T1& top()
    {
        return container.back();
    }
    
    inline int size()
    {
        return container.size();
    }
    
    inline typename T2::iterator begin()
    {
        return container.begin();
    }
    
    inline typename T2::iterator end()
    {
        return container.end();
    }
};

void show(int itr)
{
    cout << itr << endl;
}

int main()
{
    Stack<int> dStack;                  // Deque base stack
    dStack.push(10);
    dStack.push(20);
    dStack.push(30);

    cout << "Stack from Deque" << endl;
    for_each(dStack.begin(), dStack.end(), show);

    Stack<int, vector<int>> vStack;     // Vector base stack
    vStack.push(10);
    vStack.push(20);
    vStack.push(30);

    cout << "Stack from Vector" << endl;
    for_each(vStack.begin(), vStack.end(), show);
}
// Compile: clang++ -std=c++14
//              -o 02_C_StackByComposition 02_C_StackByComposition.cpp
