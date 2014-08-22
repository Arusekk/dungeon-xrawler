#include "dungeon-xrawler.hpp"

int Menu::activate() {
  unsigned int i;
  int ret;
  char c;
reload_menu:
  UI->clear();
  printf(_("Welcome, son.\n"));
  if (kind==0)
    printf(_("Main Menu:\n"));
  if (kind==1)
    printf(_("Level Select:\n"));
#ifdef __WIN32
  printf(_("[type the letter preceded by & (in th&is case it's `i') to select]\n"));
#else
  printf(_("[type the underlined letter to select]\n"));
#endif
  foreach(options,opt) {
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
  while ((ret=mapping[c]->activate())==0);
  if (ret==1)
    goto reload_menu;
  return ret-1;
}

Menu::Menu() : kind(0),options({}),mapping({}) {
  options.push_back(_("Start &Game"));
  options.push_back(_("&Level select"));
  options.push_back(_("&Help"));
  options.push_back(_("&Settings"));
  options.push_back("---------------");
  options.push_back(_("&Quit"));
  mapping['g']=mapping['G']=new Level("1");
  mapping['l']=mapping['L']=new Menu(1);
  mapping['q']=mapping['Q']=new State;
}

Menu::Menu(int n) : kind(n),options({}),mapping({}) {
  options.push_back("&1");
  options.push_back("&2");
  options.push_back("&3");
  options.push_back("---------------");
  options.push_back(_("&Quit"));
  mapping['1']=new Level("1");
  mapping['2']=new Level("2");
  mapping['3']=new Level("3");
  mapping['q']=mapping['Q']=new State;
}

Menu::~Menu() {
  delete mapping['Q'];
  if (kind==0) {
    delete mapping['G'];
    delete mapping['L'];
  }
  if (kind==1) {
    delete mapping['1'];
    delete mapping['2'];
    delete mapping['3'];
  }
}

/* EOF */
