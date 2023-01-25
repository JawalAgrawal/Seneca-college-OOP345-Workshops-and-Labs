#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <iostream>

namespace sdds {
    struct Task {
        std::string taskName;
        std::string unitsOfTime;
        std::chrono::steady_clock::duration duration;
    };

    class TimedTask {
    private:
        int numberOfRecordsStored{0};
        std::chrono::steady_clock::time_point taskStartTime;
        std::chrono::steady_clock::time_point taskEndTime;
        Task taskArray[20];
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
