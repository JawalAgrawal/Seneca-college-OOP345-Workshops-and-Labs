#include "TimedTask.h"
#include <iostream>
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
        static int taskArrIndex {0};
        taskArray[taskArrIndex].taskName = task;
        taskArray[taskArrIndex].unitsOfTime = "nanoseconds";
        taskArray[taskArrIndex].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(taskEndTime - taskStartTime);
        taskArrIndex++;
    }

    // Initializes to empty state
    void TimedTask::setEmpty() {
        numberOfRecordsStored = 0;
        taskArray = nullptr;
    }

    // Display function
    std::ostream& TimedTask::display(std::ostream& os) const {
        cout << "Execution Times:" << endl;
        cout << "--------------------------" << endl;

        // Printing the data from the array
        for (int i = 0; i < numberOfRecordsStored; i++) {
             cout << taskArray[i].taskName << " " << taskArray[i].taskName << " " << taskArray[i].unitsOfTime << endl;
        }

        cout << "--------------------------" << endl;
        return os;
    }

    // This operator should insert in the std::ostream object the records from the array
    std::ostream& operator<<(std::ostream& os, const TimedTask& timedTask) {
        return timedTask.display(os);
    }
}