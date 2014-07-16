#include "dungeon-xrawler.h"

int player_HP;
int max_player_HP;
int allowpoz(int x, int y) {
  int returnval=0;
  if (getboard(x,y+1) != '#')
    returnval |= sides::up;
  if (getboard(x,y-1) != '#')
    returnval |= sides::down;
  if (getboard(x+1,y) != '#')
    returnval |= sides::right;
  if (getboard(x-1,y) != '#')
    returnval |= sides::left;
  return returnval;
}

void printhp(int cur, int max) {
  printf("%d/%d", cur, max);
}
