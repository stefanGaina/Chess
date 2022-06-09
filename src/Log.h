#ifndef LOG_H_
#define LOG_H_

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class Log
{
public:
	static void init(void);

	static std::shared_ptr<spdlog::logger>& getLogger(void);

private:
	static std::shared_ptr<spdlog::logger> logger_;
};

/* Log macros */
#define TRACE(...)    Log::getLogger()->trace   (__VA_ARGS__)
#define INFO(...)     Log::getLogger()->info    (__VA_ARGS__)
#define WARN(...)     Log::getLogger()->warn    (__VA_ARGS__)
#define ERROR(...)    Log::getLogger()->error   (__VA_ARGS__)
#define CRITICAL(...) Log::getLogger()->critical(__VA_ARGS__)

#endif /* LOG_H_ */
