#include "dungeon-xrawler.h"

using namespace std;

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  setlocale(LC_ALL,"");
  bindtextdomain("dungeon-xrawler",".");
  textdomain("dungeon-xrawler");
  
  
  init_ui();
  rdboard("gamedata/levels/1.txt");
  outboard();
  rdboard("gamedata/art/weapons/dagger.txt");
  outboard();
  rdboard("gamedata/art/stickman.txt");
  outboard();
  rdboard("gamedata/art/stickman2.txt");
  outboard();
  rdboard("gamedata/art/stickgirl.txt");
  outboard();
  rdboard("gamedata/art/stickgirl2.txt");
  outboard();
  syspause();
  return 0;
}
