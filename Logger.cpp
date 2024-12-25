#include "Logger.hpp"
#include "TimeStamp.hpp"
Logger::Logger() : log_level_(LogLevel::ALL) { }

Logger &Logger::getInstance() {
    static Logger logger;
    return logger;
}

Logger &Logger::setLogLevel(LogLevel level) {
    log_level_ = level;
    return *this;
}

Logger::LogLevel Logger::getLogLevel() {
    return log_level_;
}

void Logger::log(const std::string &msg) {
    std::string time_str = TimeStamp::now().toString();
    std::cout << getLogLevelStr(log_level_) 
              << msg 
              << " [Time: " << time_str << "]" << std::endl;
}

std::string Logger::getLogLevelStr(LogLevel level) {
    std::string level_str;
    switch(level) {
        case LogLevel::INFO:
            level_str = "[INFO]: ";
            break;
        case LogLevel::WARNNING:
            level_str = "[WARNNING]: ";
            break;
        case LogLevel::FETAL:
            level_str = "[FETAL]: ";
            break;
        case LogLevel::DEBUG:
            level_str = "[DEBUG]: ";
            break;
    }
    return level_str;
}