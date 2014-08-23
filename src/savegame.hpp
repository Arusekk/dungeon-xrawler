#ifndef HEADER_DUNGEON_XRAWLER_SAVEGAME_HPP
#define HEADER_DUNGEON_XRAWLER_SAVEGAME_HPP

class Savegame {
  std::string file="savegame.txt";
public:
  std::set<std::string> passed={};
  void load();
  void save();
  ~Savegame();
};

extern Savegame* Save;

void save_save();

#endif // HEADER_DUNGEON_XRAWLER_SAVEGAME_HPP
