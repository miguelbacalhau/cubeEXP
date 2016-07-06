#include "Time.h"

Time::Time() {
    this->_previous_clock = std::clock();
}
double Time::getElapsedTime() {
    clock_t actual_clock = std::clock();
    double elapsed_time = actual_clock - this->_previous_clock;
    this->_previous_clock = actual_clock;

    return elapsed_time/CLOCKS_PER_SEC;
}
