#ifndef HEADER_DUNGEON_XRAWLER_SCREEN_HPP
#define HEADER_DUNGEON_XRAWLER_SCREEN_HPP

class Interface {
public:
  void clear_me();
  void pause_me();
  void init_me();
};

extern Interface* UI;


#endif // HEADER_DUNGEON_XRAWLER_SCREEN_HPP
