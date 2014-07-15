#include "dungeon-xrawler.h"

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  
  printf("Witaj, synu.\n");
  rdboard();
#ifdef __WIN32
  system("pause");
#else
  printf("Press any key to continue . . . ");
  getchar();
#endif
  return 0;
}
