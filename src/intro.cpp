#include "dungeon-xrawler.hpp"

int Intro::activate() {
  UI->clear();
  Board* Brd=new Board;
  Brd->rd("art/intro.txt");
  Brd->out_slowly();
  puts("");
  UI->printf_slowly("Dungeon Xrawler v%.20f", DUNGEON_XRAWLER_VERSION);
  puts("");
  fflush(stdout);
  UI->sleep(2);
  UI->printf_slowly("commit ");
  fflush(stdout);
  FILE* fp = popen("git rev-parse --sq HEAD 2>/dev/null","r");
  char c;
  while ((c=(char)fgetc(fp))!=EOF)
    UI->putchar_slowly(c);
  puts("");
  printf("\x1b[1;5m\t");
  UI->pause();
  printf("\x1b[0m");
  return 0;
}

/* EOF */
