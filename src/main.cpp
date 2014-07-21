#include "dungeon-xrawler.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  char *arg0=(char*)xmalloc(strlen(argv[0])+1);
  strcpy(arg0,argv[0]);
  chdir(dirname(arg0));
  free(arg0);
  chdir("..");
  chdir("gamedata");
  setlocale(LC_ALL,"");
  bindtextdomain("dungeon-xrawler","translations");
  textdomain("dungeon-xrawler");
  
  init_ui();
  if (argc>1) {
    if (strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0) {
      /// please leave untranslated the words -h and --help, and the paths like `levels/1.txt'
      printf(_("Usage: `%s [<file> ...]'\n"
	       "    or `%s -h|--help'\n"
	       "\n"
	       "<file> is of format `levels/1.txt' or `art/stickman.txt'\n"), argv[0], argv[0]);
      return 0;
    }
    /// please leave `%d` as it is changed into the number
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
