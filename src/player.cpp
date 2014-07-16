#include "dungeon-xrawler.h"

int allowpoz(int h, int w) {
  int returnval=0;
  if (board[h+1][w] != '#')
    returnval |= sides::up;
  if (board[h-1][w] != '#')
    returnval |= sides::down;
  if (board[h][w+1] != '#')
    returnval |= sides::right;
  if (board[h][w-1] != '#')
    returnval |= sides::left;
  return returnval;
}

int printhp(int cur, int max) {
  printf("%d/%d", cur, max);
}
