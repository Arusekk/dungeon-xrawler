#include "dungeon-xrawler.hpp"

int Menu::activate() {
  unsigned int i, indx;
  int ret;
  char c;
reload_menu:
  indx=0;
  UI->clear();
  printf(_("Welcome, son.\n"));
  if (kind==0)
    printf(_("Main Menu:\n"));
  if (kind==1)
    printf(_("Level Select:\n"));
  if (kind==2)
    printf(_("Help:\n"));
  if (kind==3)
    printf(_("Settings:\n"));
#ifdef __WIN32
  printf(_("[type the letter preceded by & (in th&is case it's `i') to select]\n"));
#else
  printf(_("[type the underlined letter to select]\n"));
#endif
  foreach(options,opt) {
    if (kind==0 && indx==0 && Level->Brd->h==0 && Level->Brd->w==0) {
      indx++;
      continue;
    }
    for (i=0; i<(opt->length()); i++) {
      c=(*opt)[i];
      if (kind==2 && (*opt)[i+1]==' ') {
#ifndef __WIN32
	if (c=='#')
	  printf("\x1b[1;44m");
	if (c==' ')
	  printf("\x1b[1m");
	if (c=='&')
	  printf("\x1b[1;31m");
	if (c=='@')
	  printf("\x1b[1;32m");
	if (c=='$')
	  printf("\x1b[1;33m");
	if (c=='%')
	  printf("\x1b[1;34m");
	if (c=='E')
	  printf("\x1b[1;35m");
	if (c=='+')
	  printf("\x1b[31m");
#endif
      }
#ifndef __WIN32
      if ((*opt)[i]=='&' && (*opt)[i+1]>' ') {
	printf("\x1b[4m");
	i++;
	putchar((*opt)[i]);
	printf("\x1b[0m");
	continue;
      }
#endif
      putchar((*opt)[i]);
      if (kind==2 && (*opt)[i+1]==' ') {
#ifndef __WIN32
	printf("\x1b[0m");
#endif
      }
    }
    puts("");
    indx++;
  }
bad_ltr:
  printf(_("What is your choice? "));
  printf("     \b\b\b\b\b");
  c=UI->get_letter();
  if (mapping.find(c)==mapping.end()) {
#ifndef __WIN32
    printf("\x1b[A");
#endif
    printf(_("No such option."));
    putchar(' ');
    goto bad_ltr;
  }
  while ((ret=mapping[c]->activate())==0);
  if (ret==-1) {
#ifndef __WIN32
    printf("\x1b[A");
#endif
    printf(_("No such option."));
    putchar(' ');
    goto bad_ltr;
  }
  if (ret==1)
    goto reload_menu;
  return ret-1;
}

Menu::Menu() : kind(0),options({}),mapping({}) {
  initiate();
}

Menu::Menu(int n) : kind(n),options({}),mapping({}) {
  initiate();
}

void Menu::initiate() {
  int i;
  if (kind==0) {
    options.push_back(_("&Continue"));
    options.push_back(_("New &Game"));
    options.push_back(_("&Help"));
    options.push_back(_("&Settings"));
    mapping['c']=mapping['C']=new LevelState;
    mapping['g']=mapping['G']=new Menu(1);
    mapping['h']=mapping['H']=new Menu(2);
    mapping['s']=mapping['S']=new Menu(3);
  }
  if (kind==1) {
    for (i=1; i<3; i++)
      options.push_back(strprintf(_("Start from level &%d"),i));
    mapping['1']=new LevelState("1_1");
    mapping['2']=new LevelState("1_2");
  }
  if (kind==2) {
    options.push_back(_("The idea is that you walk"));
    options.push_back(_("through dungeons and look"));
    options.push_back(_("for coins. You can obtain"));
    options.push_back(_("different armors or maybe"));
    options.push_back(_("weapons to fight varied"));
    options.push_back(_("kinds of enemies."));
    options.push_back("");
    options.push_back(_("There are many tile types:"));
    options.push_back(_(" - # - plain wall, that you"));
    options.push_back(_("       can't pass through"));
    options.push_back(_(" - & - trap, that kills you"));
    options.push_back(_("       whenever you enter it"));
    options.push_back(_(" - $ - coin (as it looks like)"));
    options.push_back(_(" - @ - you"));
    options.push_back(_(" -   - empty space"));
    /// xgettext:no-c-format please very much
    options.push_back(_(" - % - a chest with special"));
    options.push_back(_("       contents waiting for you"));
  }
  if (kind==3) {
    options.push_back(_("&Controls"));
    mapping['c']=mapping['C']=new State(1);
  }
  options.push_back("---------------");
  options.push_back(_("&Quit"));
  mapping['q']=mapping['Q']=new State;
}

Menu::~Menu() {
  delete mapping['Q'];
  if (kind==0) {
    delete mapping['C'];
    delete mapping['G'];
  }
  if (kind==1) {
    delete mapping['1'];
    delete mapping['2'];
  }
  if (kind==3) {
    delete mapping['C'];
  }
}

/* EOF */
