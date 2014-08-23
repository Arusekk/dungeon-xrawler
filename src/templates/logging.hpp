#define log_debug log_debug_f(__FILE__, __LINE__)
#define log_info log_info_f(__FILE__, __LINE__)
#define log_warning log_warning_f(__FILE__, __LINE__)
#define log_fatal log_fatal_f(__FILE__, __LINE__)

#define log_variable(vv) (log_debug << #vv " = " << log_fmt(vv) << std::endl)
#define log_ping log_debug << "PING" << std::endl
