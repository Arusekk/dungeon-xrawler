#include "dungeon-xrawler.hpp"

/** Allocates the memory and in case of no memory throws a fatal
 * @param size size of allocated bytes - best if is like count*sizeof(val)
 * @param file file where the allocation takes place
 * @param line line where the allocation takes place
 * @returns pointer to the allocated block
 */
void* xmalloc_f(size_t size, const char* file, int line) {
  void* value=malloc(size);
  if (value==0) {
    log_fatal_f(file,line) << "virtual memory exhausted" << std::endl;
  }
  assert(value!=0);
  return value;
}

std::pair<int,int> movexy(int x, int y, int side) {
  return movexy(std::make_pair(x,y),side);
}

std::pair<int,int> movexy(std::pair<int,int> returnval, int side) {
  if (side&sides::up)
    returnval.second-=1;
  if (side&sides::down)
    returnval.second+=1;
  if (side&sides::left)
    returnval.first-=1;
  if (side&sides::right)
    returnval.first+=1;
  return returnval;
}

void Board::rd() {
  rd(fn);
}

void Board::rd(std::string filename) {
  rd(filename.c_str());
}

/** Reads the board from given file name
 * @param filename path to file to read the board from (relative to gamedata/)
 */
void Board::rd(const char* filename) {
  fn=filename;
  int i,j;
  char buf[16];
  char* linia;
  bool flag;
  FILE* fp;
  if (access(filename,F_OK)) {
    log_fatal << "OMFG no such file:" << std::endl;
    log_variable(fn);
    h=w=curx=cury=0;
    return;
  }
  fp=fopen(filename,"r");

  fgets(buf, 7, fp);
  buf[4]='\0';
  h=atoi(buf);

  fgets(buf, 7, fp);
  buf[4]='\0';
  w=atoi(buf);

  fgets(buf, 7, fp);
  buf[4]='\0';
  curx=atoi(buf);

  fgets(buf, 7, fp);
  buf[4]='\0';
  cury=atoi(buf);

  if (curx!=9999 && cury!=9999) {
    fgets(buf, 16, fp);
    for (i=0; buf[i]>=' '; i++);
    buf[i]='\0';
    prev=buf;
    fgets(buf, 16, fp);
    for (i=0; buf[i]>=' '; i++);
    buf[i]='\0';
    next=buf;
  }

  xvmalloc(linia,w+3);
  for (i=0; i<h; i++) {
    fgets(linia, w+3, fp);
    flag=false;
    for (j=0; j<w; j++) {
      switch(linia[j]) {
	case '\0':
	  flag=true;
	case '.':
	case '\r':
	case '\n':
	  inboard[i][j]=' ';
	  break;
	default:
	  inboard[i][j]=linia[j];
	  break;
      }
      if (flag) inboard[i][j]=' ';
    }
  }
  free(linia);
}

/** Reads one cell of the board
 * @param x x-pos of the cell
 * @param y y-pos of the cell
 * @returns content of the cell
 */
char Board::get(int x, int y) {
  if (y>=h || y<0 || x>=w || x<0) return '#';
  return inboard[y][x];
}

char Board::get(std::pair<int,int> poz) {
  return this->get(poz.first, poz.second);
}

/** Changes one cell of the board
 * @param x x-pos of the cell
 * @param y y-pos of the cell
 * @param val new content of the cell
 */
void Board::set(int x, int y, char val) {
  if (y>=h || y<0 || x>=w || x<0) return;
  inboard[y][x]=val;
}

void Board::set(std::pair<int,int> xy, char val) {
  this->set(xy.first, xy.second, val);
}

/** Outputs the whole board to the ui
 */
void Board::out() {
  out_slowly(0);
}
void Board::out_slowly(int ms) {
  int i,j;
  char c;
  for (i=0; i<h; i++) {
    for (j=0; j<w; j++) {
      c=inboard[i][j];
      if (bound && i==Player->cury && j==Player->curx) {
	c='@';
      }
#ifndef __WIN32
      if (c=='#')
	printf("\x1b[1;44m");
      if (c==' ')
	printf("\x1b[1m");
      if (c=='&')
	printf("\x1b[1;31m");
      if (c=='@')
	printf("\x1b[1;32m");
      if (c=='$')
	printf("\x1b[1;33m");
      if (c=='%')
	printf("\x1b[1;34m");
      if (c=='E')
	printf("\x1b[1;35m");
      if (c=='+')
	printf("\x1b[31m");
#endif
      putchar(c);
#ifndef __WIN32
      if (c>=' ' && c<='~')
	printf("\x1b[0m");
#endif
    }
    puts("");
    UI->sleep(ms);
  }
}
void Board::out_slowly() {
  out_slowly(100);
}

/** Returns free cells from all the sides
 * @param x x-pos in the board
 * @param y y-pos in the board
 * @returns int value `a` that booleans like `a&sides::up` mean "is the upper cell of (x,y) free?"
 */
int Board::allowpoz(int x, int y) {
  int i, returnval=0;
  static const int sidez[4]={sides::up,sides::down,sides::right,sides::left};
  for (i=0; i<4; i++) {
    if (get(movexy(x, y, sidez[i]))!='#')
      returnval|=sidez[i];
  }
  return returnval;
}

Board::Board() : h(0), w(0), curx(0), cury(0), fn(""), bound(false), prev("none"), next("none") {
}

void Board::set_player() {
  Player->curx=curx;
  Player->cury=cury;
}

/* EOF */
