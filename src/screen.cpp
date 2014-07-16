#include "dungeon-xrawler.h"

void pause() {
#ifdef __WIN32
  system("pause");
#else
  printf("Press any key to continue . . . ");
  getchar();
#endif
}

void clear() {
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
  clear();
  printf("Witaj, synu.\n");
}
