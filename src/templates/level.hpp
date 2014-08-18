class Level : public State {
  std::string file;
  std::vector<std::string> moves;
  std::map<char,int> mapping;
  Board* Brd;
public:
  Level();
  Level(std::string name);
  Level(const Level& other);
  Level(const State& other);
  Level& operator=(const Level& other);
  int activate();
};
