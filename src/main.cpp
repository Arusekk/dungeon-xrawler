#include "dungeon-xrawler.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  chdir("..");
  chdir("gamedata");
  setlocale(LC_ALL,"");
  bindtextdomain("dungeon-xrawler","translations");
  textdomain("dungeon-xrawler");
  
  init_ui();
  if (argc>1) {
    printf(ngettext("showing %d ASCII-image\n","showing %d ASCII-images\n",argc-1), argc-1);
    for (int i=1; i<argc; i++) {
      rdboard(argv[i]);
      outboard();
    }
  }
  else {
    rdboard("levels/1.txt");
    outboard();
    rdboard("art/weapons/dagger.txt");
    outboard();
    rdboard("art/stickman.txt");
    outboard();
    rdboard("art/stickman2.txt");
    outboard();
    rdboard("art/stickgirl.txt");
    outboard();
    rdboard("art/stickgirl2.txt");
    outboard();
  }
  syspause();
  return 0;
}
