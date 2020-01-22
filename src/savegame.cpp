#include "dungeon-xrawler.hpp"

void Savegame::load() {
  atexit(save_save);
  if (access(file.c_str(),F_OK)) {
    log_debug << "savegame not yet created";
    passed.insert("none");
    return;
  }
  char buf[16];
  int siz, i, j;
  std::string curhead, orghead="DXsave";
  FILE* fp=fopen(file.c_str(),"r");

  fgets(buf, 16, fp);
  buf[6]='\0';
  curhead=buf;
  if (curhead!=orghead) {
    log_fatal << "corrupted settings file";
    passed.insert("none");
    return;
  }

  fgets(buf, 7, fp);
  buf[4]='\0';
  siz=atoi(buf);
  for (i=0; i<siz; i++) {
    fgets(buf, 16, fp);
    for (j=0; buf[j]>=' '; j++);
    buf[j]='\0';
    passed.insert(buf);
  }
}

void Savegame::save() {
  FILE* fp=fopen(file.c_str(),"w");
  fprintf(fp, "DXsave\n%04lu\n", (unsigned long)passed.size());
  foreach(passed, it) {
    fputs(it->c_str(), fp);
    fputc('\n', fp);
  }
}

Savegame::~Savegame() {
  save();
}

Savegame* Save=new Savegame;

void save_save() {
  Save->save();
}

/* EOF */
