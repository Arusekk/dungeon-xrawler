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
  int ret;
  std::pair<int,int> newpos=movexy(curx,cury,side);
  switch (bound_board->get(newpos)) {
    case '&':
      set_HP(cur_HP-rand()%5-5);
      if (cur_HP<=0) {
	coins=0;
	ret=2;
	break;
      }
    case '#':
      ret=3;
      break;
    case 'E':
      ret=1;
      break;
    case '%':
      Brd=new Board;
      Brd->rd("art/weapons/dagger.txt");
      Brd->out();
      delete Brd;
      if (1)
	bound_board->set(newpos,' ');
      UI->sleep(500);
      UI->pause();
      ret=0;
      break;
    case '$':
      bound_board->set(newpos,' ');
      coins++;
      ret=0;
      break;
    case '+':
      set_HP(cur_HP+10);
      ret=0;
      break;
    default:
      ret=0;
      break;
  }
  if (ret==3) {
    ret=0;
  }
  else {
    curx=newpos.first;
    cury=newpos.second;
  }
  return ret;
}

bool PlayerObject::allowpoz(int side) {
  return (allowpoz()&side)/side;
}

int PlayerObject::allowpoz() {
  return bound_board->allowpoz(curx, cury);
}

void PlayerObject::bind_board(Board* Brd) {
  if (bound_board)
    bound_board->bound=false;
  bound_board=Brd;
  Brd->set_player();
  Brd->bound=true;
}

/* EOF */
