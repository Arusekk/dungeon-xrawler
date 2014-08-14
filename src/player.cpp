#include "dungeon-xrawler.hpp"

PlayerObject* Player=new PlayerObject;

/** Prints HP of an object
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

PlayerObject::PlayerObject() : name("Zenon") {
  // load name from storage or ath else
}

/** Sets current HP of the player
 * @param n new value of cur_HP to set
 */
void PlayerObject::set_HP(int n) {
  cur_HP=n;
}

/** Sets max HP of the player
 * @param n new value of max_HP to set
 */
void PlayerObject::set_max_HP(int n) {
  max_HP=n;
}

/* EOF */
