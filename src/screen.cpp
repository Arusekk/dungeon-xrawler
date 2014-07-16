#include "dungeon-xrawler.h"

void syspause() {
#ifdef __WIN32
  system("pause");
#else
  printf(_("Press any key to continue . . . "));
  getchar();
#endif
}

void sysclear() {
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}

void init_ui() {
#ifdef __WIN32
  system("title Dungeon Xrawler");
#endif
  sysclear();
  printf(_("Welcome, son.\n"));
}
