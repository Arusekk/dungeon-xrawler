#include "dungeon-xrawler.h"

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  init_ui();
  rdboard("gamedata/levels/1.txt");
  outboard();
  rdboard("gamedata/art/weapons/dagger.txt");
  outboard();
  rdboard("gamedata/art/stickman.txt");
  outboard();
  pause();
  return 0;
}
