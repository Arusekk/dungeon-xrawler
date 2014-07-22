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

/* EOF */
