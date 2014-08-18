#ifndef HEADER_DUNGEON_XRAWLER_STATE_HPP
#define HEADER_DUNGEON_XRAWLER_STATE_HPP

class State {
  friend class Menu;
  int kind;
public:
  State();
  State(int n);
  virtual ~State();
  virtual int activate();
  int activate() const;
};


#endif // HEADER_DUNGEON_XRAWLER_STATE_HPP
