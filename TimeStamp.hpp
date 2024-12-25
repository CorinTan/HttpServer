#pragma once

#include "Copyable.hpp"
#include <chrono>
#include <string>

class TimeStamp : public Copyable{
public:
    using TimePoint = std::chrono::system_clock::time_point;
    TimeStamp() = default;
    explicit TimeStamp(const TimePoint &time_point) : time_point_(time_point) { }
    
    TimePoint getTimePoint() const {
        return time_point_;
    }
    
    static TimeStamp now() {
        return TimeStamp(std::chrono::system_clock::now());
    }

    std::string toString() const {
        time_t time = std::chrono::system_clock::to_time_t(time_point_);
        std::string time_str = std::ctime(&time);
        if (time_str.back() == '\n')
            time_str.back() = '\0';  // 去除换行
        return time_str;
    }

private:
    TimePoint time_point_;
};