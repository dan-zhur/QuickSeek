#pragma once

#include <string>


namespace config
{
#if defined(_WIN32)
#define __CONFIG_WINDOWS__
	using String = std::wstring;
	using Char = String::value_type;
	inline Char MakeChar(char c) { return c; }
#else
#define __CONFIG_POSIX__
	using String = std::string;
	using Char = String::value_type;
	inline Char MakeChar(char c) { return c; }
#endif
}