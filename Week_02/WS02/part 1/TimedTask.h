#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H

#include <iostream>

namespace sdds {
    struct Task {
        std::string taskName;
        std::string unitOfTime;
        std::chrono::duration<int> seconds_type;
    };
    class TimedTask {
    private:
        int numberOfRecordsStored;
        std::chrono::time_point<std::chrono::steady_clock> taskStartTime;
        std::chrono::time_point<std::chrono::steady_clock> taskEndTime;
        Task* taskArray;

    public:
        TimedTask();

        // A modifier that starts the timer for an event
        void startClock();

        // A modifier that stops the timer for an event
        void stopClock();

        // This function will update the next time-record in the array
        void addTask();
    };

    // Should insert in the std::ostream object the records from the array
    std::ostream& operator<<(std::ostream& os, const TimedTask& timedTask);
}

#endif // SDDS_TIMEDTASK_H
