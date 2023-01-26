/*
*****************************************************************************
                              TimedTask.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 January 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <iostream>
#include <chrono>

namespace sdds {
    struct Task {
        std::string taskName {};
        std::string unitsOfTime {};
        std::chrono::steady_clock::duration duration {};
    };

    class TimedTask {
    private:
        int numberOfRecordsStored {0};
        std::chrono::steady_clock::time_point taskStartTime {};
        std::chrono::steady_clock::time_point taskEndTime {};
        Task taskArray[10];
    public:
        TimedTask();

        // A modifier that starts the timer for an event
        void startClock();

        // A modifier that stops the timer for an event
        void stopClock();

        // This function will update the next time-record in the array
        void addTask(const char *task);

        // Initializes to empty state
        void setEmpty();

        // This operator should insert in the std::ostream object the records from the array
        friend std::ostream &operator<<(std::ostream &os, const TimedTask& timedTask);
    };
}
#endif // SDDS_TIMEDTASK_H
