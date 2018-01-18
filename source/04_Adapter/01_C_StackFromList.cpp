// 01_C_StackFromList.cpp
#include <iostream>
#include <list>
using namespace std;

// Prohibits the original functions of list
template <typename T>
class Stack : private list<T>
{
public:
    inline void push(const T& a)
    {
        list<T>::push_back(a);
    }

    inline void pop()
    {
        list<T>::pop_back();
    }

    inline T& top()
    {
        return list<T>::back();
    }
    
    inline int size()
    {
        return list<T>::size();
    }
    
    // Typename let compile know list<T> is type
    inline typename list<T>::iterator begin()
    {
        return list<T>::begin();
    }
    
    inline typename list<T>::iterator end()
    {
        return list<T>::end();
    }
};

int main()
{
    Stack<int> stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);

    int i = 0;
    //stack.push_front(10);           // push_front is forbidden
    for (auto num : stack)
    {
        cout << "Index: " << i++ << ", Value: " << num << endl;
    }

    cout << "Size at start: " << stack.size() << endl;
    int size = stack.size();
    for (int i=0; i<size; i++)
    {
        // Get a value of top
        int top = stack.top();
        cout << "Pop: " << top << ", remain: " << stack.size() << endl;
        // Remove top value
        stack.pop();
    }

    return 0;
}
// Compile: clang++ -std=c++14
//              -o 01_C_StackFromList 01_C_StackFromList.cpp
