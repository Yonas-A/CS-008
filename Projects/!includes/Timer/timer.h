/*
 *  A class that uses clock function from the time.h and
 *  ctime library to find duartion of a start time and
 *  stop time
 */

#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <time.h>


class Timer
{

private:

    clock_t _start = 0;
    clock_t _stop = 0;

public:

    Timer(): _start(clock()), _stop(clock()) {
    }

    void start()    {
        _start = clock();
    }

    void stop() {
        _stop = clock();
    }

    double duration()
    {
        const bool DEBUG = false;
        if(DEBUG)
        {
            std::cout << "[" <<  double(_stop) << "-" << double(_start)
                 << "] / " << CLOCKS_PER_SEC << std::endl;
        }

        return ( float(_stop) - float(_start) ) / CLOCKS_PER_SEC;
    }

};

#endif // TIMER_H
