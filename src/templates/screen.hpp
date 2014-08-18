class Interface {
public:
  State* CurrState;
  void clear_me();
  void pause_me();
  void init_me();
  char get_letter();
};

extern Interface* UI;
