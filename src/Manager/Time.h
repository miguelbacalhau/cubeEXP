#ifndef INCLUDED_TIMEMANAGER
#define INCLUDED_TIMEMANAGER

#include <ctime>

class Time {

    private:
        clock_t _previous_clock;
    public:
        Time();
        double getElapsedTime();
};
#endif
