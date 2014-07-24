#include "dungeon-xrawler.hpp"

Interface* UI=new Interface;

/** Pauses the user interface
 */
void Interface::pause_me() {
#ifdef __WIN32
  system("pause");
#else
  printf(_("Press any key to continue . . . "));
  getchar();
#endif
}

/** Clears the screen
 */
void Interface::clear_me() {
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}

/** Initializes user interface
 */
void Interface::init_me() {
#ifdef __WIN32
  system("title Dungeon Xrawler");
#endif
  clear_me();
  printf(_("Welcome, son.\n"));
  printhp_pl();
}

/* EOF */
