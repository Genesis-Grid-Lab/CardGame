#pragma once
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>



// include spdlog
#define FMT_HEADER_ONLY
#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


class Logger
{
public:
    using SPDLog = std::shared_ptr<spdlog::logger>;

    inline Logger()
    {
	m_SPD = spdlog::stdout_color_mt("stdout");
	spdlog::set_level(spdlog::level::trace);
	spdlog::set_pattern("%^[%T]: [#%t] %v%S");
    }

    inline static SPDLog& Ref()
    {
	static Logger logger;
	return logger.m_SPD;
    }
private:
    SPDLog m_SPD;
};

#define TRACE(...) Logger::Ref()->trace(__VA_ARGS__)
#define DEBUG(...) Logger::Ref()->debug(__VA_ARGS__)
#define INFO(...) Logger::Ref()->info(__VA_ARGS__)
#define WARN(...) Logger::Ref()->warn(__VA_ARGS__)
#define ERROR(...) Logger::Ref()->error(__VA_ARGS__)
#define FATAL(...) Logger::Ref()->critical(__VA_ARGS__)
