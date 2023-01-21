#include "TimedTask.h"
#include <iostream>
#include <cstring>
using namespace sdds;

namespace sdds {
    TimedTask::TimedTask() {

    }

    // A modifier that starts the timer for an event
    void TimedTask::startClock() {

    }

    // A modifier that stops the timer for an event
    void TimedTask::stopClock() {

    }

    // This function will update the next time-record in the array
    void TimedTask::addTask(const char* task) {

    }

    // Initializes to empty state
    void TimedTask::setEmpty() {
        numberOfRecordsStored = 0;
        taskArray = nullptr;
    }
}