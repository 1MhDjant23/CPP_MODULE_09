#include "TimeTracker.hpp"

TimeTracker::TimeTracker() : startTime(0), endTime(0), elapsedTime(0) {}
TimeTracker::~TimeTracker() {}

void    TimeTracker::start() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = (tv.tv_sec * 1e6) + tv.tv_usec; // Convert to microseconds
}

void    TimeTracker::stop() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    endTime = (tv.tv_sec * 1e6) + tv.tv_usec; // Convert to microseconds
}

void    TimeTracker::setElapsedTime() {
    elapsedTime = (endTime - startTime); 
}

void    TimeTracker::displayElapsedTime(typeList containerType, size_t size) const {
    std::string type = (containerType == VECTOR) ? "vector" : "deque";
    std::cout << "Time to process a range of " << size << " elements with std::"<< type << " : " << std::fixed << std::setprecision(5) << elapsedTime << " us" << std::endl;
}

void    TimeTracker::reset() {
    startTime = 0;
    endTime = 0;
    elapsedTime = 0;
}