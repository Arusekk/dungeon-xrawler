#include "dungeon-xrawler.h"

void rdboard(char *filename) {
  int i,j;
  FILE *fp;
  fp=fopen(filename,"r");
  char buf[7];
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_h=atoi(buf);
  fgets(buf, 7, fp);
  buf[4]='\0';
  board_w=atoi(buf);
  char linia[board_w+3];
  for (i=0; i<board_h; i++) {
    fgets(linia, board_w+3, fp);
    for (j=0; j<board_w; j++) {
      board[i][j]=linia[j];
    }
  }
}

void outboard()
{
for(int i = 0; i < board_h; i++)
	{
	for(int j = 0; j < board_w; j++)
		printf("%c", board[i][j]);
	printf("\n");
	}	
}





