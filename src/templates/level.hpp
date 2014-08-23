class LevelObj : public State {
  std::string file;
  std::vector<std::string> moves;
  std::map<char,int> mapping;
public:
  Board* Brd;
  LevelObj();
  LevelObj(std::string name);
  LevelObj(const char* name);
  LevelObj(const LevelObj& other);
  LevelObj(const State& other);
  LevelObj& operator=(const LevelObj& other);
  void initiate();
  int activate();
  void rd();
  template<class T>
  void rd(T f) {
    file=f;
    rd();
  }
};

extern LevelObj* Level;

class LevelState : public State {
  int backlvl;
  std::string file;
public:
  LevelState();
  LevelState(std::string name);
  LevelState(const char* name);
  int activate();
};
