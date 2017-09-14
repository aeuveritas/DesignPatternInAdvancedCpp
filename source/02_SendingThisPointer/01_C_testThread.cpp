// 01_C_testThread.cpp
#include <iostream>

#include <pthread.h>

using namespace std;

void* foo(void *p)
{
    string* str = static_cast<string*>(p);
    cout << str->c_str() << endl;

    return NULL;
}

int main() {
    pthread_t tid;
    string str = "Thread Start";

    // Create thread
    pthread_create(&tid, NULL, foo, static_cast<void*>(&str));

    // Wait for thread
    pthread_join(tid, NULL);
    
    cout << "Thread id: " << tid << endl;
    return 0;
}
// Compile: clang++ -pthread 
//          -o 01_C_testThread 01_C_testThread.cpp
