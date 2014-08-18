#ifndef HEADER_DUNGEON_XRAWLER_SCREEN_HPP
#define HEADER_DUNGEON_XRAWLER_SCREEN_HPP

class Interface {
public:
  State* CurrState;
  void clear_me();
  void pause_me();
  void init_me();
  char get_letter();
};

extern Interface* UI;


#endif // HEADER_DUNGEON_XRAWLER_SCREEN_HPP
