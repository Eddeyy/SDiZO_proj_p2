//
// Created by thero on 20.06.2022.
//

#ifndef SDIZO_PROJ_P2_T_TIMER_H
#define SDIZO_PROJ_P2_T_TIMER_H

#include <windows.h>
#include <iostream>

class Timer {

    double PCFreq = 0.0;
    __int64 CounterStart = 0;
    LARGE_INTEGER li{};

    void reset()
    {
        PCFreq = 0.0;
        CounterStart = 0;
    }

public:

    Timer() = default;

    void startTimer();
    double stopTimer();
};


#endif //SDIZO_PROJ_P2_T_TIMER_H
