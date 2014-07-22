#include "dungeon-xrawler.hpp"

/** Finds the output for logs to keep
 * @returns normally std::cerr
 */
static std::ostream& get_logging_instance() {
  return std::cerr;
}

/** Puts prefix and file/line info into the logging instance and returns it
 * @param prefix string like [ERROR]
 * @param file file where the event happened
 * @param line line where the event happened
 * @returns logging instance with prefix already written
 */
static std::ostream& log_generic_f(const char* prefix, const char* file, int line) {
  get_logging_instance() << prefix << " " << file << ":" << line << " ";
  return get_logging_instance();
}

/** Puts file/line debug info into the logging instance and returns it
 * @param file file where the event happened
 * @param line line where the event happened
 * @returns logging instance with prefix already written
 */
std::ostream& log_debug_f(const char* file, int line) {
  return log_generic_f("[DEBUG]", file, line);
}

/** Puts file/line informational info into the logging instance and returns it
 * @param file file where the event happened
 * @param line line where the event happened
 * @returns logging instance with prefix already written
 */
std::ostream& log_info_f(const char* file, int line) {
  return log_generic_f("[INFO]", file, line);
}

/** Puts file/line warning info into the logging instance and returns it
 * @param file file where the event happened
 * @param line line where the event happened
 * @returns logging instance with prefix already written
 */
std::ostream& log_warning_f(const char* file, int line) {
  return log_generic_f("[WARNING]", file, line);
}

/** Puts file/line fatal info into the logging instance and returns it
 * @param file file where the event happened
 * @param line line where the event happened
 * @returns logging instance with prefix already written
 */
std::ostream& log_fatal_f(const char* file, int line) {
  return log_generic_f("[FATAL]", file, line);
}

/** Helper function to output vectors of stings
 * @param out output stream
 * @param vec vector
 * @returns out with vector put out
 */
std::ostream& operator<<(std::ostream& out, std::vector<std::string> vec) {
    foreach(vec,i)
      out << *i << " ";
    return out;
}

/* EOF */
