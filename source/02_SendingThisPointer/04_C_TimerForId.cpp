// 04_C_TimerForId.cpp
#include <iostream>
#include <map>
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

class TimerLib
{
    string name;
    vector<Timer*> timers;
    // Map for this pointer
    static map<int, TimerLib*> this_map;

public:
    TimerLib(string s)
        : name(s)
    {}

    void start(int sec)
    {
        Timer* timer = setTimer(sec, timerHandler);

        // Store this pointer to map
        this_map[timer->first] = this;

        timers.push_back(timer);
    }

    static void* timerHandler(void* p)
    {
        Timer* timer = static_cast<Timer*>(p);

        // Get this pointer from map
        TimerLib* self = this_map[timer->first];

        sleep(timer->second);

        cout << "Thread id: " << timer->first
             << ", time: " << timer->second
             << ", Name: " << self->name << endl;

        return NULL;
    }

    void wait()
    {
        waitTimer(timers);
    }
};

// A static member variable should be declared
// globally again
map<int, TimerLib*> TimerLib::this_map;

int main()
{
    TimerLib c1("AAA");
    TimerLib c2("BBB");

    // Start timer
    c1.start(10);
    c2.start(5);

    // Wait for timer
    c1.wait();
    c2.wait();

    return 0;
}

// Compile: clang++ -pthread
//          -o 04_C_TimerForId 04_C_TimerForId.cpp
