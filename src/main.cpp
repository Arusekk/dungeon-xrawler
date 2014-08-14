#include "dungeon-xrawler.hpp"

int main(int argc, char* argv[]) {
  char* arg0;
  xvmalloc(arg0,strlen(argv[0])+1);
  strcpy(arg0,argv[0]);
  chdir(dirname(arg0));
  free(arg0);
  chdir("gamedata");
  setlocale(LC_ALL,"");
  bindtextdomain("dungeon-xrawler","translations");
  textdomain("dungeon-xrawler");
  
  
  if (argc>1) {
    std::vector<std::string> args;
    for (int i=0; i<argc; i++) {
      args.push_back(argv[i]);
    }
    log_variable(args);
    if (args[1]=="-h" || args[1]=="--help") {
      /// please leave untranslated the words -h and --help, and the paths like `levels/1.txt'
      printf(_("Usage: `%s [<file> ...]'\n"
	       "    or `%s -h|--help'\n"
	       "\n"
	       "<file> is of format `levels/1.txt' or `art/stickman.txt'\n"), argv[0], argv[0]);
      return 0;
    }
    UI->init_me();
    /// please leave `%d` as it is changed into the number
    printf(ngettext("showing %d ASCII-image\n","showing %d ASCII-images\n",argc-1), argc-1);
    Board* Img=new Board;
    for (int i=1; i<argc; i++) {
      Img->rd(argv[i]);
      Img->out();
    }
  }
  else {
    Player->set_HP(69);
    Player->set_max_HP(123);
    UI->init_me();
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
  }
  UI->pause_me();
  return 0;
}

/* EOF */
