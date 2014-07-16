#ifndef __PLAYER_H__
#define __PLAYER_H__

enum sides {
  up=1, down=2, left=4, right=8
};
int allowpoz(int x, int y);
void printhp(int cur, int max); 

#endif // __PLAYER_H__
