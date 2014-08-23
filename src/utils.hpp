#ifndef HEADER_DUNGEON_XRAWLER_UTILS_HPP
#define HEADER_DUNGEON_XRAWLER_UTILS_HPP

#define foreach(tab,it) for(decltype(tab)::iterator it=(tab).begin(); it!=(tab).end(); it++)
#define foreachs(kind,tab,it) for(decltype(tab)::kind##_iterator it=(tab).begin(); it!=(tab).end(); it++)

void pass();
char swapcase(char c);
std::string swapcase(std::string s);
std::string stringify(char* str);
std::string strprintf(const char* fmt, ...);

#endif // HEADER_DUNGEON_XRAWLER_UTILS_HPP
