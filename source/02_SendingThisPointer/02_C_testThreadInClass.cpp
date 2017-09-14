// 02_C_testThreadInClass.cpp
#include <iostream>

#include <pthread.h>

using namespace std;

// Library
class ThreadLib
{
private:
    pthread_t tid;

public:    
    ThreadLib()
    : tid(0)
    {}
    
    void run()
    {
        // Create thread
        pthread_create(&tid, NULL, _threadLoop, this);
        
        // Wait for thread
        pthread_join(tid, NULL);
        cout << "Thread id: " << tid << endl;
        
        return;
    }

    static void* _threadLoop(void* p)
    {
        ThreadLib* const self = static_cast<ThreadLib*>(p);

        self->threadLoop();     // threadLoop(self)

        return NULL;
    }

    virtual bool threadLoop()
    {
        cout << "ThreadLib's threadLoop" << endl;
        
        return false;
    }
};

// User defined library
class MyThreadLib : public ThreadLib
{
    virtual bool threadLoop()
    {
        cout << "MyThreadLib's threadLoop" << endl;

        return true;
    }
};

int main()
{
    MyThreadLib t;
    
    t.run();                    // Thread is created and
                                // threadLoop() of MyThreadLib is executed

    return 0;
}
// Compile: clang++ -pthread 
//          -o 02_C_testThreadInClass 02_C_testThreadInClass.cpp
