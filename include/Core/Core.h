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
#include <map>



// include spdlog
#define FMT_HEADER_ONLY
#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

//inlcude glew
#define GLEW_STATIC
#include <GL/glew.h>
//include glfw
#include <GLFW/glfw3.h>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>


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

template <typename T>
inline constexpr uint32_t TypeID()
{
    return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
}

#define TRACE(...) Logger::Ref()->trace(__VA_ARGS__)
#define DEBUG(...) Logger::Ref()->debug(__VA_ARGS__)
#define INFO(...) Logger::Ref()->info(__VA_ARGS__)
#define WARN(...) Logger::Ref()->warn(__VA_ARGS__)
#define ERROR(...) Logger::Ref()->error(__VA_ARGS__)
#define FATAL(...) Logger::Ref()->critical(__VA_ARGS__)

//free allocated memory
#define DELETE(ptr) if (ptr != nullptr) { delete (ptr); ptr = nullptr;}

// runtime assertion
#define APP_ASSERT assert

// compile assertion
#if defined(__clang__) || defined(__gcc__)
#define APP_STATIC_ASSERT _Static_assert
#else
#define APP_STATIC_ASSERT static_assert
#endif

