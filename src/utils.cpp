#include "dungeon-xrawler.hpp"

/** Does exactly nothing
 */
void pass() {
}

/** Swaps UPPERCASE and lowercase
 */
char swapcase(char c) {
  if ('a'<=c && c<='z')
    return (char)(c+('A'-'a'));
  if ('A'<=c && c<='Z')
    return (char)(c+('a'-'A'));
  return c;
}

std::string swapcase(std::string s) {
  std::stringstream ss;
  foreach (s,c)
    ss << swapcase(*c);
  return ss.str();
}

std::string stringify(char* str) {
  std::string ret=str;
  return ret;
}

std::string strprintf(const char* fmt, ...) {
  char buf[1000];
  va_list rest;
  va_start(rest,fmt);
  vsprintf(buf,fmt,rest);
  va_end(rest);
  return buf;
}

/* EOF */
