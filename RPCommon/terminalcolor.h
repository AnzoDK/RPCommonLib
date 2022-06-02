#pragma once
#ifndef NO_COLOR
#define TERMINAL_COLOR_RESET "\e[0m"
#define TERMINAL_COLOR_RED "\e[1;31m"
#define TERMINAL_COLOR_GREEN "\e[1;32m"
#define TERMINAL_COLOR_YELLOW "\e[1;33m"
#define TERMINAL_COLOR_BLUE "\e[1;34m"

#else

#define TERMINAL_COLOR_RESET ""
#define TERMINAL_COLOR_RED  ""
#define TERMINAL_COLOR_GREEN ""
#define TERMINAL_COLOR_YELLOW ""
#define TERMINAL_COLOR_BLUE ""

#endif
