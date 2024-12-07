#include <bits/stdc++.h>
#include "../include/lch.h"

using namespace std;

/* 
    @brief Gives the current system time in microseconds
    @return Current system time in microseconds
*/
TimePoint TimeNow() {
    return chrono::high_resolution_clock::now();
}

/* 
    @brief Calculates the time difference between `start` and current time
    @param `start` Start of the interval
    @param `precision` Whether to print microseconds, milliseconds, or seconds elapsed since start (default: MILLISECONDS)
    @param `division` What to divide the result of end-start by, useful for calculating average time in loops (default: 1)
    @return String of format "`Time elapsed: {time} {unit}`\n"
*/
string TimeElapsed(TimePoint start, TimePrecision precision, int division) {

    if (division == 0) 
        throw invalid_argument(
            RED_START +
            string("[ERROR]: Attempted to divide by 0 due to invalid parameter in TimeElapsed(TimePoint, TimePrecision, int)") +
            RESET_COLOR
        );

    string res;
    if (precision ==  TimePrecision::MICROSECONDS) {
        chrono::duration<double, micro> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + to_string(elapsed) + " us\n");
    }
    
    else if (precision ==  TimePrecision::MILLISECONDS) {
        chrono::duration<double, milli> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + to_string(elapsed) + " ms\n");
    }

    else if (precision ==  TimePrecision::SECONDS) {
        chrono::duration<double> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + to_string(elapsed) + " s\n");
    }

    else {
        throw invalid_argument(
            RED_START +
            string("[ERROR]: Invalid precision parameter passed to TimeElapsed(TimePoint, TimePrecision, int)") +
            RESET_COLOR
        );
    }

    return res;
}

/* 
    @brief Calculates the time difference between `start` and current time
    @param start Start of the interval
    @param end End of the interval
    @param division What to divide the result of end-start by, useful for calculating average time in loops
    @return String of format "Time elapsed: {time} us\n"
*/
string TimeElapsed(TimePoint start, TimePoint end, int division) {

    if (division == 0) 
        throw invalid_argument("Division by 0 in TimeElapsed(TimePoint, Timepoint, int)");
    
    chrono::duration<double, micro> duration = end - start;
    double elapsed = duration.count() / division;

    return string("Time elapsed: " + to_string(elapsed) + " us\n");
}