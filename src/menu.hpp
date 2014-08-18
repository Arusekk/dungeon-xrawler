#ifndef HEADER_DUNGEON_XRAWLER_MENU_HPP
#define HEADER_DUNGEON_XRAWLER_MENU_HPP

class Menu : public State {
  int kind;
  std::vector<std::string> options;
  std::map<char,State*> mapping;
public:
  Menu();
  Menu(int n);
  ~Menu();
  int activate();
};


#endif // HEADER_DUNGEON_XRAWLER_MENU_HPP
