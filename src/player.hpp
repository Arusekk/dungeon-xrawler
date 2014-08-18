#ifndef HEADER_DUNGEON_XRAWLER_PLAYER_HPP
#define HEADER_DUNGEON_XRAWLER_PLAYER_HPP

class PlayerObject: public MazeObject {
  std::string name;
  Board* bound_board;
public:
  int coins;
  int curx,cury;
  PlayerObject();
  PlayerObject(const PlayerObject& other);
  PlayerObject& operator=(const PlayerObject& other);
  std::string get_name();
  void bind_board(Board* brd);
  int won(int side);
  int allowpoz();
  bool allowpoz(int side);
};

extern PlayerObject* Player;

void printhp(int cur, int max);
void printhp_pl();

#endif // HEADER_DUNGEON_XRAWLER_PLAYER_HPP
