#ifndef HEADER_DUNGEON_XRAWLER_MAZEOBJECT_H
#define HEADER_DUNGEON_XRAWLER_MAZEOBJECT_H

class MazeObject {
  friend class PlayerObject;
  int cur_HP;
  int max_HP;
public:
  MazeObject();
  virtual ~MazeObject();
  void print_hp();
};

#endif // HEADER_DUNGEON_XRAWLER_MAZEOBJECT_H
