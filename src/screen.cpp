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
  CurrState=new Menu();
  CurrState->activate();
  /*
  Board* Brd=new Board;
  Brd->rd("levels/1.txt");
  Brd->out();
  Brd->rd("art/weapons/dagger.txt");
  Brd->out();
  Brd->rd("art/stickman.txt");
  Brd->out();
  Brd->rd("art/stickman2.txt");
  Brd->out();
  Brd->rd("art/stickgirl.txt");
  Brd->out();
  Brd->rd("art/stickgirl2.txt");
  Brd->out();
  */
  delete CurrState;
}

char Interface::get_letter() {
  char c,ret;
wrong:
  ret=(char)getchar();
  if (ret<'0' || (ret>'9' && ret<'A') || (ret>'Z' && ret<'a') || ret>'z')
    goto wrong;
  while ((c=(char)getchar())!='\n');
  return ret;
}

/* EOF */
