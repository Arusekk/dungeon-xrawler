class Menu : public State {
  int kind;
  std::vector<std::string> options;
  std::map<char,State*> mapping;
public:
  Menu();
  Menu(int n);
  ~Menu();
  void initiate();
  int activate();
};
