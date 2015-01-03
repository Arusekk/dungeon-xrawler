#include "dungeon-xrawler.hpp"

Interface* UI=new Interface;

/** Pauses the user interface
 */
void Interface::pause() {
#ifdef __WIN32
  system("pause");
#else
  printf(_("Press any key to continue . . . "));
  anykey();
  puts("");
#endif
}

void Interface::printf_slowly(const char* fmt, ...) {
  char temptab[MAXBOARD];
  va_list params;
  va_start(params, fmt);
  vsprintf(temptab, fmt, params);
  va_end(params);
  for (char* it=temptab; *it; it++)
    putchar_slowly(*it);
}


/** Sleeps for a given number of seconds
 */
void Interface::sleep(int ms) {
  timespec tim, tim2;
  tim.tv_sec = ms/1000;
  tim.tv_nsec = 1000000L*(ms%1000);
  int err;
  if ((err=nanosleep(&tim, &tim2))<0) {
    log_debug << "nanosleep failed [Errno " << err << "]";
  }
}

/** Clears the screen
 */
void Interface::clear() {
#ifdef __WIN32
  system("cls");
#else
//   system("clear");
  printf("\x1b[H\x1b[J");
#endif
}

/** Initializes user interface
 */
void Interface::init() {
#ifdef __WIN32
  system("title Dungeon Xrawler");
#endif
  CurrState=new Intro();
  Save->load();
  CurrState->activate();
  delete CurrState;
  
  CurrState=new Menu();
  CurrState->activate();
  /*
  Board* Brd=new Board;
  Brd->rd("levels/1.txt");
  Brd->out();
  Brd->rd("art/weapons/dagger.txt");
  Brd->out();
  Brd->rd("art/stickman.txt");
  Brd->out();
  Brd->rd("art/stickman2.txt");
  Brd->out();
  Brd->rd("art/stickgirl.txt");
  Brd->out();
  Brd->rd("art/stickgirl2.txt");
  Brd->out();
  */
  delete CurrState;
}

char Interface::anykey() {
#ifdef __WIN32
  while (!_kbhit());
  return _getch();
#else
  termios_set_input_mode();
  return (char)getchar();
  termios_reset_input_mode();
#endif
}

char Interface::get_letter() {
  std::string arrows="wsda";
  char ret;
wrong:
  ret=anykey();
  if (ret=='\x1b')
    if ((ret=anykey())=='[') {
      ret=anykey();
      if (ret>='A' && ret<='D')
	ret=arrows[ret-'A'];
    }
  if (ret<'0' || (ret>'9' && ret<'A') || (ret>'Z' && ret<'a') || ret>'z')
    goto wrong;
  puts("");
  return ret;
}


/* Źródło: The GNU C Library Reference Manual */
/*-------------------------------------------------------------*/
/* Use this variable to remember original terminal attributes. */
struct termios termios_saved_attributes;

void termios_reset_input_mode() {
  tcsetattr (STDIN_FILENO, TCSANOW, &termios_saved_attributes);
}

void termios_set_input_mode() {
  struct termios tattr;
  /* Make sure stdin is a terminal. */
  if (!isatty (STDIN_FILENO))
    {
      fprintf (stderr, "Not a terminal.\n");
      exit (EXIT_FAILURE);
    }
  /* Save the terminal attributes so we can restore them later. */
  tcgetattr (STDIN_FILENO, &termios_saved_attributes);
  atexit (termios_reset_input_mode);
  /* Set the funny terminal modes. */
  tcgetattr (STDIN_FILENO, &tattr);
  tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
  tattr.c_cc[VMIN] = 1;
  tattr.c_cc[VTIME] = 0;
  tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}
/*-------------------------------------------------------------*/

/* EOF */
