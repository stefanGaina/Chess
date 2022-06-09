#include "pch.h"
#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Log::logger_ = nullptr;

void Log::init(void)
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	logger_ = spdlog::stdout_color_mt("Chess");
	logger_->set_level(spdlog::level::trace);

	INFO("Logger successfully initialized!");
}

std::shared_ptr<spdlog::logger>& Log::getLogger(void)
{
	return logger_;
}
