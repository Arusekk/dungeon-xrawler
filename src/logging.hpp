#ifndef HEADER_DUNGEON_XRAWLER_LOGGING_HPP
#define HEADER_DUNGEON_XRAWLER_LOGGING_HPP

#include "logging.h"

std::ostream& log_debug_f(const char* file, int line);
std::ostream& log_info_f(const char* file, int line);
std::ostream& log_warning_f(const char* file, int line);
std::ostream& log_fatal_f(const char* file, int line);
std::ostream& operator<<(std::ostream& out, std::vector<std::string> vec);

#endif // HEADER_DUNGEON_XRAWLER_LOGGING_HPP
