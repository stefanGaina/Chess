#include "pch.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include "spdlog/sinks/rotating_file_sink.h"

#define MB 1048576

std::shared_ptr<spdlog::logger> Log::s_console_logger_ = nullptr;
std::shared_ptr<spdlog::logger> Log::s_file_logger_ = nullptr;

void Log::init(void)
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	spdlog::enable_backtrace(32);

	s_console_logger_ = spdlog::stdout_color_mt("Chess");
	s_console_logger_->set_level(spdlog::level::CONSOLE_LOG_LEVEL);

	s_file_logger_ = spdlog::rotating_logger_mt("File_Chess", "log/messages.txt", 5 * MB, 3);
	s_file_logger_->set_level(spdlog::level::FILE_LOG_LEVEL);

	INFO("Logger successfully initialized!");
}

std::shared_ptr<spdlog::logger>& Log::getConsoleLogger(void)
{
	return s_console_logger_;
}

std::shared_ptr<spdlog::logger>& Log::getFileLogger(void)
{
	return s_file_logger_;
}
