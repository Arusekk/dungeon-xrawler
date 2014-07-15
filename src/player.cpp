#include "dungeon-xrawler.h"
int allowpoz(int h, int w)
{
bool up, down, left, right;
up = down = left = right = true;	
if(board[h+1][w] == '#')
up = false;	
if(board[h-1][w] == '#')
down = false;		
if(board[h][w+1] == '#')
right = false;		
if(board[h][w-1] == '#')
left = false;
  return (up<<3)+(down<<2)+(left<<1)+right;
}

int printhp(int a, int b) 
{
printf("%d", a);
printf("/");	
printf("%d", b);	
}
