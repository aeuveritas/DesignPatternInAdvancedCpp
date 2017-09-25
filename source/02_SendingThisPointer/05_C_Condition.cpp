// 05_C_Condition.cpp
#include <iostream>
#include <vector>

#include <unistd.h>
#include <pthread.h>

using namespace std;

typedef pair<pthread_t, int> Timer;

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

void* foo(void* p)
{
    Timer* timer = static_cast<Timer*>(p);
    int time = timer->second;

    sleep(time);

    // Print message
    switch (time) {
    case 10:
        cout << "Interval 10" << endl;
        break;
    case 5:
        cout << "Interval 5" << endl;
        break;
    default:
        cout << "Wrong time interval" << endl;
    }

    return NULL;
}

int main()
{
    vector<Timer*> timers;
    timers.push_back(setTimer(10, foo));
    timers.push_back(setTimer(5, foo));

    waitTimer(timers);

    return 0;
}
// Compile: clang++ -pthread
//          -o 05_C_Condition 05_C_Condition.cpp
