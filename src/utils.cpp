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

/* EOF */
