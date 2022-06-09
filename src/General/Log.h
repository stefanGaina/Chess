#ifndef LOG_H_
#define LOG_H_

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#define CONSOLE_LOG_LEVEL debug
#define FILE_LOG_LEVEL    trace

class Log
{
public:
	static void init(void);

	static std::shared_ptr<spdlog::logger>& getConsoleLogger(void);
	static std::shared_ptr<spdlog::logger>& getFileLogger(void);

private:
	static std::shared_ptr<spdlog::logger> s_console_logger_;
	static std::shared_ptr<spdlog::logger> s_file_logger_;
};

/* Log macros */
#define BACKTRACE(...) spdlog                 ::debug   (__VA_ARGS__)
#define TRACE(...)     { Log::getConsoleLogger()->trace   (__VA_ARGS__); Log::getFileLogger()->trace(__VA_ARGS__); }
#define INFO(...)      { Log::getConsoleLogger()->info    (__VA_ARGS__); Log::getFileLogger()->info (__VA_ARGS__); }
#define DEBUG(...)     Log::getConsoleLogger()->debug   (__VA_ARGS__)
#define WARN(...)      Log::getConsoleLogger()->warn    (__VA_ARGS__)
#define ERROR(...)     Log::getConsoleLogger()->error   (__VA_ARGS__)
#define CRITICAL(...)  Log::getConsoleLogger()->critical(__VA_ARGS__)

#endif /* LOG_H_ */
