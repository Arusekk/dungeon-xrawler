class State {
  friend class Menu;
  int kind;
public:
  State();
  State(int n);
  virtual ~State();
  virtual int activate();
  int activate() const;
};
