#include "../include/lch.hpp"

using std::string;
using std::chrono::duration;
using std::invalid_argument;

/* 
    @brief Gives the current system time in microseconds
    @return Current system time in microseconds
*/
TimePoint TimeNow() {
    return std::chrono::high_resolution_clock::now();
}

/* 
    @brief Calculates the time difference between `start` and current time
    @param `start` Start of the interval
    @param `precision` Whether to print microseconds, milliseconds, or seconds elapsed since start (default: MILLISECONDS)
    @param `division` What to divide the result of end-start by, useful for calculating average time in loops (default: 1)
    @return String of format "`Time elapsed: {time} {unit}`\n"

    NOTE: If you want to pass a division parameter, you also need to pass a TimePrecision parameter, you cant skip it
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
        duration<double, std::micro> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " us\n");
    }
    
    else if (precision ==  TimePrecision::MILLISECONDS) {
        duration<double, std::milli> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " ms\n");
    }

    else if (precision ==  TimePrecision::SECONDS) {
        duration<double> duration = TimeNow() - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " s\n");
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
    @param `start` Start of the interval
    @param `end` End of the interval
    @param `precision` Whether to print microseconds, milliseconds, or seconds elapsed since start (default: MILLISECONDS)
    @param `division` What to divide the result of end-start by, useful for calculating average time in loops (default: 1)
    @return String of format "`Time elapsed: {time} {unit}`\n"

    NOTE: If you want  to pass a division parameter, you also need to pass a TimePrecision parameter, you cant skip it
    ToDo: Look for a way to merge these two functions
*/
string TimeElapsed(TimePoint start, TimePoint end, TimePrecision precision, int division) {

    if (division == 0) 
        throw invalid_argument(
            RED_START +
            string("[ERROR]: Attempted to divide by 0 due to invalid parameter in TimeElapsed(TimePoint, TimePrecision, int)") +
            RESET_COLOR
        );

    string res;
    if (precision ==  TimePrecision::MICROSECONDS) {
        duration<double, std::micro> duration = end - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " us\n");
    }
    
    else if (precision ==  TimePrecision::MILLISECONDS) {
        duration<double, std::milli> duration = end - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " ms\n");
    }

    else if (precision ==  TimePrecision::SECONDS) {
        duration<double> duration = end - start;
        double elapsed = duration.count() / division;
        res = string("Time elapsed: " + std::to_string(elapsed) + " s\n");
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