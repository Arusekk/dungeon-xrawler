#ifndef HEADER_DUNGEON_XRAWLER_LOGGING_HPP
#define HEADER_DUNGEON_XRAWLER_LOGGING_HPP

#define log_debug log_debug_f(__FILE__, __LINE__)
#define log_info log_info_f(__FILE__, __LINE__)
#define log_warning log_warning_f(__FILE__, __LINE__)
#define log_fatal log_fatal_f(__FILE__, __LINE__)

#define log_variable(vv) (log_debug << #vv " = " << log_fmt(vv) << std::endl)

std::ostream& log_debug_f(const char* file, int line);
std::ostream& log_info_f(const char* file, int line);
std::ostream& log_warning_f(const char* file, int line);
std::ostream& log_fatal_f(const char* file, int line);
template <class T> std::string log_fmt(std::vector<T> vec);
std::string log_fmt(std::string str);
template <class T> std::string log_fmt(T ipt);
void bekon();

#endif // HEADER_DUNGEON_XRAWLER_LOGGING_HPP
