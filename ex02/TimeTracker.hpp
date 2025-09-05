#ifndef TIMETRACKER_HPP
#define TIMETRACKER_HPP

#include <iostream>
#include <sys/time.h>
#include <iomanip>
enum typeList {
    VECTOR,
    DEQUE,
    CHAIN,
    LIST
};

class TimeTracker {
    private:
        double startTime;
        double endTime;
        double elapsedTime;
        TimeTracker(const TimeTracker& other);
        TimeTracker& operator=(const TimeTracker& other);
    public:
        TimeTracker();
        ~TimeTracker();
        void    start();
        void    stop();
        void    setElapsedTime();
        void    displayElapsedTime(typeList containerType, size_t size) const;
        void    reset();
};


#endif // TIMETRACKER_HPP