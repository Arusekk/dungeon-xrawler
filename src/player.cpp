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

PlayerObject::PlayerObject() : name("Zenon"), bound_board(0), curx(0), cury(0) {
  // load name from storage or ath else
}

PlayerObject::PlayerObject(const PlayerObject& other) : name(other.name), bound_board(0), curx(0), cury(0) {
  set_HP(other.cur_HP);
  set_max_HP(other.max_HP);
}

PlayerObject& PlayerObject::operator=(const PlayerObject& other) {
  name=other.name;
  set_HP(other.cur_HP);
  set_max_HP(other.max_HP);
  return *this;
}

int PlayerObject::won(int side) {
  std::pair<int,int> newpos=movexy(curx,cury,side);
  curx=newpos.first;
  cury=newpos.second;
  switch (bound_board->get(curx,cury)) {
    case '&':
      return 2;
    case 'E':
      return 1;
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
