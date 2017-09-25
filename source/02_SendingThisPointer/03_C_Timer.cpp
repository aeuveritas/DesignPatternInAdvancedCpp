// 03_C_Timer.cpp
#include <iostream>
#include <vector>

#include <unistd.h>
#include <pthread.h>

using namespace std;

typedef pair<pthread_t, int> Timer;
void* foo(void* p)
{
    // Get timer information
    Timer* timer = static_cast<Timer*>(p);

    // Wait
    sleep(timer->second);

    cout << "Thread id: " << timer->first
         << ", time: " << timer->second << endl;

    return NULL;
}

Timer* setTimer(int _time, void* (*func)(void*))
{
    Timer* timer = new Timer();
    timer->second = _time;

    // Create thread
    pthread_create(&(timer->first), NULL, func, static_cast<void*>(timer));

    return timer;
}

typedef vector<Timer*>::iterator TIterator;
void waitTimer(vector<Timer*>& timer)
{
    for (TIterator tItr = timer.begin(); tItr != timer.end(); ++tItr) {
        // Wait for thread
        pthread_join((*tItr)->first, NULL);

        // Clear memory
        delete *tItr;
        *tItr = NULL;
    }
}

int main()
{
    vector<Timer*> timers;

    // Set timer
    timers.push_back(setTimer(10, foo));
    timers.push_back(setTimer(5, foo));

    waitTimer(timers);

    return 0;
}
// Compile: clang++ -pthread
//          -o 03_C_Timer 03_C_Timer.cpp
