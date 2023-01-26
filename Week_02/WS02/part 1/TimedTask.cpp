#include "TimedTask.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
    TimedTask::TimedTask() {
        setEmpty();
    }

    // A modifier that starts the timer for an event
    void TimedTask::startClock() {
        taskStartTime = std::chrono::steady_clock::now();
    }

    // A modifier that stops the timer for an event
    void TimedTask::stopClock() {
        taskEndTime = std::chrono::steady_clock::now();
    }

    // This function will update the next time-record in the array
    void TimedTask::addTask(const char* task) {
        if (numberOfRecordsStored < 10) {
            if (task) {
                taskArray[numberOfRecordsStored].taskName = task;
                taskArray[numberOfRecordsStored].unitsOfTime = "nanoseconds";
                taskArray[numberOfRecordsStored].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(taskEndTime - taskStartTime);
                // Incrementing the number of records
                numberOfRecordsStored++;
            }
        }
    }

    // Initializes to empty state
    void TimedTask::setEmpty() {
        numberOfRecordsStored = 0;
    }

    // This operator should insert in the std::ostream object the records from the array
    std::ostream& operator<<(std::ostream& os, const TimedTask& timedTask) {
        os << "--------------------------" << endl;
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;

        // Printing the data from the array
        for (int i = 0; i < timedTask.numberOfRecordsStored; i++) {
            os << left << setw(21) << timedTask.taskArray[i].taskName
            << right << setw(13) << timedTask.taskArray[i].duration.count()
            << " " << timedTask.taskArray[i].unitsOfTime << endl;
        }

        os << "--------------------------" << endl;
        return os;
    }
}