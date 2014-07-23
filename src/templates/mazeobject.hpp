class MazeObject {
  friend class PlayerObject;
  int cur_HP;
  int max_HP;
public:
  MazeObject();
  virtual ~MazeObject();
  void print_hp();
};
