#include "dungeon-xrawler.h"

void rdboard(char *filename) {
  int i,j;
  char buf[7];
  bool flag;
  FILE *fp;
  fp=fopen(filename,"r");
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_h=atoi(buf);
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_w=atoi(buf);
  char linia[board_w+3];
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
}

void outboard() {
  int i,j;
  for (i=0; i<board_h; i++) {
    for (j=0; j<board_w; j++)
      printf("%c", board[i][j]);
    printf("\n");
  }
}
