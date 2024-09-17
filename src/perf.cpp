#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

/* 
    @brief Gives the current system time in microseconds
    @return Current system time in microseconds
*/
TimePoint TimeNow_Microseconds() {
    return chrono::high_resolution_clock::now();
}

/* 
    @brief Calculates the time difference between `start` and current time
    @param start Start of the interval
    @param division What to divide the result of end-start by, useful for calculating average time in loops
    @return String of format "Time elapsed: {time} us\n"
*/
string TimeElapsed_Microseconds(TimePoint start, int division) {

    if (division == 0) 
        throw invalid_argument("Division by 0 in TimeElapsedMicroseconds(TimePoint, int)");

    chrono::duration<double, micro> duration = TimeNow_Microseconds() - start;
    double elapsed = duration.count() / division;

    return string("Time elapsed: " + to_string(elapsed) + " us\n");
}

/* 
    @brief Calculates the time difference between `start` and current time
    @param start Start of the interval
    @param end End of the interval
    @param division What to divide the result of end-start by, useful for calculating average time in loops
    @return String of format "Time elapsed: {time} us\n"
*/
string TimeElapsed_Microseconds(TimePoint start, TimePoint end, int division) {

    if (division == 0) 
        throw invalid_argument("Division by 0 in TimeElapsedMicroseconds(TimePoint, Timepoint, int)");
    
    chrono::duration<double, micro> duration = end - start;
    double elapsed = duration.count() / division;

    return string("Time elapsed: " + to_string(elapsed) + " us\n");
}