#include "dungeon-xrawler.hpp"

int State::activate() {
  return kind;
}
int State::activate() const {
  return kind;
}

State::State() : kind(2) {
}
State::State(int n) : kind(n) {
}
State::~State() {
}

/* EOF */
