#include "dungeon-xrawler.h"

int main() {
  printf("Witaj, synu.");
#ifdef __WIN32
  system("pause");
#else
  printf("\nPress any key to continue . . . ");
  getchar();
#endif
  return 0;
}
