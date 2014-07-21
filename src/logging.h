#ifndef HEADER_DUNGEON_XRAWLER_LOGGING_H
#define HEADER_DUNGEON_XRAWLER_LOGGING_H

#define log_debug log_debug_f(__FILE__, __LINE__)
#define log_info log_info_f(__FILE__, __LINE__)
#define log_warning log_warning_f(__FILE__, __LINE__)
#define log_fatal log_fatal_f(__FILE__, __LINE__)

#define log_variable(vv) (log_debug << #vv " = " << vv << std::endl)

#endif // HEADER_DUNGEON_XRAWLER_LOGGING_H
