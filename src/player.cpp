#include "dungeon-xrawler.hpp"

PlayerObject* Player=new PlayerObject;

/** Prints HP of anything
 * @param cur current health
 * @param max maximum health
 */
void printhp(int cur, int max) {
  int curr=cur, maxx=max;
  if (max<10) {
    curr*=7;
    maxx*=7;
  }
  int step=maxx/4-1;
  if (maxx&3) step++;
  step=std::max(step,1);
  for (int i=0; i<maxx; i+=step)
    if (curr<i)
	putchar('.');
    else if (curr-i<=step/2)
	putchar('o');
    else
	putchar('O');
  printf(" [%d/%d]", cur, max);
  puts("");
}

/** Prints HP of the player
 */
void printhp_pl() {
  /// HP is an international shortcut for Health Points
  printf(_("Your HP: "));
  Player->print_hp();
}

std::string PlayerObject::get_name() {
  return name;
}

PlayerObject::PlayerObject() : name("Zenon"), bound_board(0), coins(0), curx(9999), cury(9999) {
  // load name from storage or ath else
}

PlayerObject::PlayerObject(const PlayerObject& other) : name(other.name), bound_board(other.bound_board), coins(other.coins), curx(other.curx), cury(other.cury) {
  set_HP(other.cur_HP);
  set_max_HP(other.max_HP);
}

PlayerObject& PlayerObject::operator=(const PlayerObject& other) {
  name=other.name;
  coins=other.coins;
  set_HP(other.cur_HP);
  set_max_HP(other.max_HP);
  curx=other.curx;
  cury=other.cury;
  return *this;
}

int PlayerObject::won(int side) {
  Board* Brd;
  std::pair<int,int> newpos=movexy(curx,cury,side);
  curx=newpos.first;
  cury=newpos.second;
  switch (bound_board->get(curx,cury)) {
    case '&':
      coins=0;
      return 2;
    case 'E':
      return 1;
    case '%':
      Brd=new Board;
      Brd->rd("art/weapons/dagger.txt");
      Brd->out();
      delete Brd;
      if (1)
	bound_board->set(curx,cury,' ');
      UI->pause_me();
      return 0;
    case '$':
      bound_board->set(curx,cury,' ');
      coins++;
      return 0;
    default:
      return 0;
  }
}

bool PlayerObject::allowpoz(int side) {
  return (allowpoz()&side)/side;
}

int PlayerObject::allowpoz() {
  return bound_board->allowpoz(curx, cury);
}

void PlayerObject::bind_board(Board* Brd) {
  bound_board=Brd;
  Brd->set_player();
}

/* EOF */
