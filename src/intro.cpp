#include "dungeon-xrawler.hpp"

int Intro::activate() {
  UI->clear();
  Board* Brd=new Board;
  Brd->rd("art/intro.txt");
  Brd->out_slowly();
  puts("");
  UI->printf_slowly("Dungeon Xrawler v%f", DUNGEON_XRAWLER_VERSION);
  puts("");
  fflush(stdout);
  UI->sleep(2);
  printf("\x1b[1;5m\t");
  UI->pause();
  printf("\x1b[0m");
  return 0;
}

/* EOF */
