#ifndef __STORAGE_H__
#define __STORAGE_H__

#define MAXBOARD 200

char board[MAXBOARD][MAXBOARD];
int board_h,board_w;
void rdboard(char *filename);
void outboard();

#endif // __STORAGE_H__
