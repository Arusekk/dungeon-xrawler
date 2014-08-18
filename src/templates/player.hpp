class PlayerObject: public MazeObject {
  std::string name;
  Board* bound_board;
public:
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
