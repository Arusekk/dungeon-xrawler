#ifndef HEADER_DUNGEON_XRAWLER_PLAYER_H
#define HEADER_DUNGEON_XRAWLER_PLAYER_H

enum sides {
  up=1, down=2, left=4, right=8
};

class PlayerObject: public MazeObject {
  std::string name;
public:
  PlayerObject();
  std::string get_name();
  void set_HP(int n);
  void set_max_HP(int n);
};

extern PlayerObject* Player;

#endif // HEADER_DUNGEON_XRAWLER_PLAYER_H
