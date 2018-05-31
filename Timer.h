//
// Created by Acer on 2018-05-30.
//

#ifndef OOP_TASK_4_TIMER_H
#define OOP_TASK_4_TIMER_H

#include <chrono>

using laikas = std::chrono::high_resolution_clock;
using std::chrono::time_point;

class Timer {
private:
    laikas::time_point start;
public:
    Timer() : start{laikas::now()} {}
    void reset(){ start = laikas::now(); }
    double getTime(){
        return std::chrono::duration<double>(laikas::now() - start).count();
    }
};

#endif //OOP_TASK_4_TIMER_H
