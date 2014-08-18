#include "dungeon-xrawler.hpp"

/** Prints current object's HP
 */
void MazeObject::print_hp() {
  /// HP is an international shortcut for Health Points
  printhp(cur_HP,max_HP);
}

MazeObject::MazeObject() : cur_HP(50), max_HP(100) {
}
MazeObject::~MazeObject() {
}

/** Sets current HP of an object
 * @param n new value of cur_HP to set
 */
void MazeObject::set_HP(int n) {
  cur_HP=n;
}

/** Sets max HP of an object
 * @param n new value of max_HP to set
 */
void MazeObject::set_max_HP(int n) {
  max_HP=n;
}

/* EOF */
