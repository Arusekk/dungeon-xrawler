#ifndef __STORAGE_H__
#define __STORAGE_H__

#define MAXBOARD 200

char getboard(int x, int y);
void setboard(int x, int y, char val);
void rdboard(char *filename);
void outboard();

#endif // __STORAGE_H__
