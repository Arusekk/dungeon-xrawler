#include "dungeon-xrawler.hpp"

int LevelObj::activate() {
  unsigned int i;
  int side;
  char c;
  if (!Brd->bound) {
    rd();
  }
reload_lvl:
  if (Brd->w==0 && Brd->h==0) return 1;
  UI->clear();
  printf(_("Level of %s"), file.c_str());
  puts("");
  if (Save->passed.find(Brd->prev)==Save->passed.end()) {
    puts(_("You haven't unlocked this level yet."));
    printf(_("To unlock it, pass the %s level"), Brd->prev.c_str());
    puts("");
    rd(Brd->prev);
    UI->pause();
    goto reload_lvl;
  }
  Brd->out();
  printf(_("Welcome, son.\n"));
  printhp_pl();
  printf(_("Cash: %d$\n"), Player->coins);
  printf(_("Available moves:\n"));
#ifdef __WIN32
  printf(_("[type the letter preceded by & (in th&is case it's `i') to select]\n"));
#else
  printf(_("[type the underlined letter to select]\n"));
#endif
  foreach(moves,opt) {
    for (i=0; i<(opt->length()); i++) {
#ifndef __WIN32
      if ((*opt)[i]=='&') {
	printf("\x1b[4m");
	i++;
	putchar((*opt)[i]);
	printf("\x1b[0m");
	continue;
      }
#endif
      putchar((*opt)[i]);
    }
    puts("");
  }
bad_ltr:
  printf(_("What is your choice? "));
  printf("    \b\b\b\b");
  c=UI->get_letter();
  if (mapping.find(c)==mapping.end()) {
#ifndef __WIN32
    printf("\x1b[A");
#endif
    printf(_("No such option."));
    putchar(' ');
    goto bad_ltr;
  }
  side=mapping[c];
  if (side==0)
    return 1;
  if (!Player->allowpoz(side)) {
#ifndef __WIN32
    printf("\x1b[A");
#endif
    printf(_("The path is blocked."));
    putchar(' ');
    goto bad_ltr;
  }
  side=Player->won(side);
  if (side==1) {
    puts(_("You have won."));
    Save->passed.insert(file);
    rd(Brd->next);
    UI->pause();
  }
  if (side==2) {
    puts(_("You have lost."));
    rd();
    UI->pause();
  }
  goto reload_lvl;
}

LevelObj::LevelObj() : file("1_1"), moves({}), mapping({}), Brd(new Board) {
  initiate();
}

LevelObj::LevelObj(std::string name) : file(name), moves({}), mapping({}), Brd(new Board) {
  initiate();
}
LevelObj::LevelObj(const char* name) : file(name), moves({}), mapping({}), Brd(new Board) {
  initiate();
}

LevelObj::LevelObj(const State& other) : file("1_1"), moves({}), mapping({}), Brd(new Board) {
  other.activate();
}

void LevelObj::initiate() {
  moves.push_back(_("Up (&W)"));
  moves.push_back(_("Down (&S)"));
  moves.push_back(_("Left (&A)"));
  moves.push_back(_("Right (&D)"));
  moves.push_back("---------");
  moves.push_back(_("&Quit"));
  mapping['w']=mapping['W']=sides::up;
  mapping['s']=mapping['S']=sides::down;
  mapping['a']=mapping['A']=sides::left;
  mapping['d']=mapping['D']=sides::right;
  mapping['q']=mapping['Q']=0;
  if (0)
    rd();
}

void LevelObj::rd() {
  std::stringstream fn;
  fn << "levels/" << file << ".txt";
  Brd->rd(fn.str());
  Player->bind_board(Brd);
}

LevelObj& LevelObj::operator=(const LevelObj& other) {
  file=other.file;
  moves=other.moves;
  mapping=other.mapping;
  Brd=other.Brd;
  return *this;
}

LevelState::LevelState() : backlvl(0), file("1_1") {
}

LevelState::LevelState(const char* filename) : backlvl(1), file(filename) {
}

LevelState::LevelState(std::string filename) : backlvl(1), file(filename) {
}

int LevelState::activate() {
  if (backlvl)
    Level->rd(file);
  else if (Level->Brd->h==0 && Level->Brd->w==0)
    return -1;
  return Level->activate();
}

/* EOF */
