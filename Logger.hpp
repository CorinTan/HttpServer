#pragma once
#include "NonCopyable.hpp"

#include <iostream>
#include <string>

class Logger : NonCopyable {
public:
    enum class LogLevel {
        INFO,
        WARNNING,
        FETAL,
        DEBUG,
        ALL,
    };
    
    static Logger &getInstance();

    Logger &setLogLevel(LogLevel );
    LogLevel getLogLevel();
    
    void log(const std::string &msg);

private:
    Logger();

    std::string getLogLevelStr(LogLevel );
    LogLevel log_level_;
};

inline void LOG_INFO(const std::string &msg) {
    Logger::getInstance().setLogLevel(Logger::LogLevel::INFO).log(msg);
}

inline void LOG_WARNNING(const std::string &msg) {
    Logger::getInstance().setLogLevel(Logger::LogLevel::WARNNING).log(msg);
}

inline void LOG_FETAL(const std::string &msg) {
    Logger::getInstance().setLogLevel(Logger::LogLevel::FETAL).log(msg);
}

inline void LOG_DEBUG(const std::string &msg) {
    #ifdef MUDEBUG
        Logger::getInstance().setLogLevel(Logger::LogLevel::DEBUG).log(msg);
    #else
        return ;
    #endif
}
