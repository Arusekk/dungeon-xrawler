#ifndef HEADER_DUNGEON_XRAWLER_STORAGE_HPP
#define HEADER_DUNGEON_XRAWLER_STORAGE_HPP

#define MAXBOARD 200
#define xmalloc(s) xmalloc_f(s,__FILE__,__LINE__)
#define xvmalloc(v,s) v=(decltype(v))xmalloc(s)

enum sides {
  up=1, down=2, left=4, right=8 // WSAD
};

class Board {
  char inboard[MAXBOARD][MAXBOARD];
public:
  int h, w;
private:
  int curx,cury;
  std::string fn;
public:
  bool bound;
  std::string prev,next;
  Board();
  char get(int x, int y);
  char get(std::pair<int,int> poz);
  void set(int x, int y, char val);
  void set(std::pair<int,int> xy, char val);
  void out();
  void out_slowly();
  void out_slowly(int ms);
  void rd();
  void rd(std::string filename);
  void rd(const char* filename);
  void set_player();
  int allowpoz(int x, int y);
};

void* xmalloc_f(size_t size, const char* file, int line);
std::pair<int,int> movexy(int x, int y, int side);
std::pair<int,int> movexy(std::pair<int,int> returnval, int side);

#endif // HEADER_DUNGEON_XRAWLER_STORAGE_HPP
