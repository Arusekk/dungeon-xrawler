#include "dungeon-xrawler.hpp"

int Level::activate() {
  std::stringstream* next;
  unsigned int i;
  int side;
  char c;
  Player->bind_board(Brd);
reload_lvl:
  UI->clear_me();
  Brd->out();
  printf(_("Welcome, son.\n"));
  printhp_pl();
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
  c=UI->get_letter();
  if (mapping.find(c)==mapping.end()) {
    puts(_("No such option."));
    goto bad_ltr;
  }
  side=mapping[c];
  if (side==0)
    return 1;
  if (!Player->allowpoz(side)) {
    puts(_("The path is blocked."));
    goto bad_ltr;
  }
  side=Player->won(side);
  if (side==1) {
    puts(_("You have won."));
    next=new std::stringstream;
    *next << atoi(file.c_str())+1;
    file=next->str();
    delete next;
    next=new std::stringstream;
    *next << "levels/" << file << ".txt";
    Brd->rd(next->str());
    delete next;
    Player->bind_board(Brd);
    UI->pause_me();
  }
  if (side==2) {
    puts(_("You have lost."));
    Brd->rd();
    Player->bind_board(Brd);
    UI->pause_me();
  }
  goto reload_lvl;
}

Level::Level() : file("1"), moves({}), mapping({}), Brd(new Board) {
  moves.push_back(_("&Up"));
  moves.push_back(_("&Down"));
  moves.push_back(_("&Left"));
  moves.push_back(_("&Right"));
  moves.push_back("---------");
  moves.push_back(_("&Quit"));
  mapping['u']=mapping['U']=sides::up;
  mapping['d']=mapping['D']=sides::down;
  mapping['l']=mapping['L']=sides::left;
  mapping['r']=mapping['R']=sides::right;
  mapping['q']=mapping['Q']=0;
  std::stringstream fn;
  fn << "levels/" << file << ".txt";
  Brd->rd(fn.str());
}

Level::Level(std::string name) : file(name), moves({}), mapping({}), Brd(new Board) {
  moves.push_back(_("&Up"));
  moves.push_back(_("&Down"));
  moves.push_back(_("&Left"));
  moves.push_back(_("&Right"));
  moves.push_back("---------");
  moves.push_back(_("&Quit"));
  mapping['u']=mapping['U']=sides::up;
  mapping['d']=mapping['D']=sides::down;
  mapping['l']=mapping['L']=sides::left;
  mapping['r']=mapping['R']=sides::right;
  mapping['q']=mapping['Q']=0;
  std::stringstream fn;
  fn << "levels/" << file << ".txt";
  Brd->rd(fn.str());
}

Level::Level(const State& other) : file("1"), moves({}), mapping({}), Brd(new Board) {
  other.activate();
}

Level& Level::operator=(const Level& other) {
  file=other.file;
  moves=other.moves;
  mapping=other.mapping;
  Brd=other.Brd;
  return *this;
}

/* EOF */
