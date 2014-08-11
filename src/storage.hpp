#ifndef HEADER_DUNGEON_XRAWLER_STORAGE_HPP
#define HEADER_DUNGEON_XRAWLER_STORAGE_HPP

#define MAXBOARD 200
#define xmalloc(s) xmalloc_f(s,__FILE__,__LINE__)
#define xvmalloc(v,s) v=(decltype(v))xmalloc(s)

class Board {
  char inboard[MAXBOARD][MAXBOARD];
  int h, w;
public:
  char get(int x, int y);
  void set(int x, int y, char val);
  void out();
  void rd(const char* filename);
};


#endif // HEADER_DUNGEON_XRAWLER_STORAGE_HPP
