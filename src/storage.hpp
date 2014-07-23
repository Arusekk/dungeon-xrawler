#ifndef HEADER_DUNGEON_XRAWLER_STORAGE_HPP
#define HEADER_DUNGEON_XRAWLER_STORAGE_HPP

#define MAXBOARD 200
#define xmalloc(s) xmalloc_f(s,__FILE__,__LINE__)
#define xvmalloc(v,s) v=(decltype(v))xmalloc(s)

void* xmalloc_f(size_t size, const char* file, int line);
void rdboard(const char* filename);
char getboard(int x, int y);
void setboard(int x, int y, char val);
void outboard();

#endif // HEADER_DUNGEON_XRAWLER_STORAGE_HPP
