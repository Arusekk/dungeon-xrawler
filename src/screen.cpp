#include "dungeon-xrawler.hpp"

/** Pauses the user interface
 */
void syspause() {
#ifdef __WIN32
  system("pause");
#else
  printf(_("Press any key to continue . . . "));
  getchar();
#endif
}

/** Clears the screen
 */
void sysclear() {
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}

/** Initializes user interface
 */
void init_ui() {
#ifdef __WIN32
  system("title Dungeon Xrawler");
#endif
  sysclear();
  printf(_("Welcome, son.\n"));
  printhp_pl();
}

/* EOF */
