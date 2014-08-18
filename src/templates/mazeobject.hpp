class MazeObject {
  friend class PlayerObject;
  int cur_HP;
  int max_HP;
public:
  MazeObject();
  virtual ~MazeObject();
  void set_HP(int n);
  void set_max_HP(int n);
  void print_hp();
};
