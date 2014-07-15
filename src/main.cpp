#include "dungeon-xrawler.h"

int main(int argc, char *argv[]) {
#ifndef __WIN32
  chdir(dirname(argv[0]));
#endif
  printf("Witaj, synu.\n");
  rdboard("data/levels/1.txt");
  outboard();
#ifdef __WIN32
  system("pause");
#else
  printf("Press any key to continue . . . ");
  getchar();
#endif
  return 0;
}
