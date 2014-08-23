class Savegame {
  std::string file="savegame.txt";
public:
  std::set<std::string> passed={};
  void load();
  void save();
  ~Savegame();
};

extern Savegame* Save;
