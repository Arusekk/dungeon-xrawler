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

/** Reads the board from given file name
 * @param filename path to file to read the board from (relative to gamedata/)
 */
void Board::rd(const char* filename) {
  int i,j;
  char buf[7];
  char* linia;
  bool flag;
  FILE* fp;
  fp=fopen(filename,"r");
  fgets(buf, 7, fp);
  buf[4]='\0';
  h=atoi(buf);
  fgets(buf, 7, fp);
  buf[4]='\0';
  w=atoi(buf);
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

/** Changes one cell of the board
 * @param x x-pos of the cell
 * @param y y-pos of the cell
 * @param val new content of the cell
 */
void Board::set(int x, int y, char val) {
  inboard[y][x]=val;
}

/** Outputs the whole board to the ui
 */
void Board::out() {
  int i,j;
  for (i=0; i<h; i++) {
    for (j=0; j<w; j++)
      printf("%c", inboard[i][j]);
    puts("");
  }
}

/* EOF */
