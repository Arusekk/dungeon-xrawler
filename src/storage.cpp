#include "dungeon-xrawler.hpp"

char board[MAXBOARD][MAXBOARD];
int board_h,board_w;

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
void rdboard(const char* filename) {
  int i,j;
  char buf[7];
  char* linia;
  bool flag;
  FILE* fp;
  fp=fopen(filename,"r");
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_h=atoi(buf);
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_w=atoi(buf);
  xvmalloc(linia,board_w+3);
  for (i=0; i<board_h; i++) {
    fgets(linia, board_w+3, fp);
    flag=false;
    for (j=0; j<board_w; j++) {
      switch(linia[j]) {
	case '\0':
	  flag=true;
	case '.':
	case '\r':
	case '\n':
	  board[i][j]=' ';
	  break;
	default:
	  board[i][j]=linia[j];
	  break;
      }
      if (flag) board[i][j]=' ';
    }
  }
  free(linia);
}

/** Reads one cell of the board
 * @param x x-pos of the cell
 * @param y y-pos of the cell
 * @returns content of the cell
 */
char getboard(int x, int y) {
  return board[y][x];
}

/** Changes one cell of the board
 * @param x x-pos of the cell
 * @param y y-pos of the cell
 * @param val new content of the cell
 */
void setboard(int x, int y, char val) {
  board[y][x]=val;
}

/** Outputs the whole board to the ui
 */
void outboard() {
  int i,j;
  for (i=0; i<board_h; i++) {
    for (j=0; j<board_w; j++)
      printf("%c", board[i][j]);
    puts("");
  }
}

/* EOF */
