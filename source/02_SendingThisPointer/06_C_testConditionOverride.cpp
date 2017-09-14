// 06_C_testConditionOverride.cpp
#include <iostream>
#include <vector>
#include <map>

#include <unistd.h>
#include <pthread.h>

using namespace std;

typedef pair<pthread_t, int> Timer;

Timer* setTimer(int _time, void* (*func)(void *))
{
    Timer* timer = new Timer();
    timer->second = _time;
    
    // Create thread
    pthread_create(&(timer->first), NULL, func, static_cast<void*>(timer));
    
    return timer;
}

typedef vector<Timer *>::iterator TIterator;
void waitTimer(vector<Timer *>& timer)
{
    for (TIterator tItr = timer.begin(); tItr != timer.end(); ++tItr)
    {
        // Wait for thread
        pthread_join((*tItr)->first, NULL);
        
        // Clear memory
        delete *tItr;
        *tItr = NULL;
    }
}

// Library
class TimerLib
{
    vector<Timer *> timers;
    // Map for this pointer
	static map<int, TimerLib*> this_map;

public:
	void start(int sec)
	{
        Timer* timer = setTimer(sec, foo);
                
        // Store this pointer to map
        this_map[timer->first] = this;
        
        timers.push_back(timer);
	}
	
	static void* foo(void* p)
    {
        Timer* timer = static_cast<Timer*>(p);
        
        // Get this pointer from map
        pthread_t handle = timer->first;
        int time = timer->second;
        TimerLib* self = this_map[handle];
        
        sleep(time);
        
        // Call print method
        switch (time)
        {
        case 10:
            self->waitSec10();
            break;
        case 5:
            self->waitSec5();
            break;
        default:
            self->wrongSec();
        }

        return NULL;
    }
    
	void wait()
    {
        waitTimer(timers);
    }

	virtual void waitSec10() {}
	virtual void waitSec5() {}
	virtual void wrongSec() {}
};

// User's Class
class MyTimeLib : public TimerLib
{
public:
    // Print method
	virtual void waitSec10()
	{
		cout << "Interval 10" << endl;
	}

	virtual void waitSec5()
	{
		cout << "Interval 5" << endl;
	}
	
	virtual void wrongSec()
    {
        cout << "Wrong time interval" << endl;
    }
};

map<int, TimerLib*> TimerLib::this_map;

int main()
{
	MyTimeLib t;

    // Start timer
	t.start(10);		

    // Wait for timer
	t.wait();

	return 0;
}
// Compile: clang++ -pthread 
//          -o 06_C_testConditionOverride 06_C_testConditionOverride.cpp
