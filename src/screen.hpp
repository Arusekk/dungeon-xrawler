#ifndef HEADER_DUNGEON_XRAWLER_SCREEN_HPP
#define HEADER_DUNGEON_XRAWLER_SCREEN_HPP

class Interface {
public:
  State* CurrState;
  void clear();
  void pause();
  void init();
  template<class T> void putchar_slowly(T c){
    putchar(c);
    fflush(stdout);
    this->sleep(100);
  }
  void printf_slowly(const char* fmt, ...);
//   template<typename... Args>
//   void printf_slowly(const char* fmt, Args... rest) {
//     char temptab[MAXBOARD];
//     temptab[0]=0;
//     sprintf(temptab, fmt, rest...);
//     for (char* it=temptab; *it; it++)
//       putchar_slowly(*it);
//   }
  void sleep(int n);
  char anykey();
  char get_letter();
};

extern Interface* UI;

void termios_reset_input_mode();
void termios_set_input_mode();

#endif // HEADER_DUNGEON_XRAWLER_SCREEN_HPP
