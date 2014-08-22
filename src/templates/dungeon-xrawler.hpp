#define DUNGEON_XRAWLER_VERSION 1.4142135623730951

#ifdef __WIN32
  #include <windows.h>
  #include <conio.h>
#else
  #include <termios.h>
  #include <unistd.h>
#endif

#include <libgen.h>
#include <locale.h>
#include <libintl.h>
#define _ gettext

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
