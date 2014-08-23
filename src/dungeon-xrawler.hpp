#ifndef HEADER_DUNGEON_XRAWLER_DUNGEON_XRAWLER_HPP
#define HEADER_DUNGEON_XRAWLER_DUNGEON_XRAWLER_HPP

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

#include "logging.hpp"
#include "utils.hpp"
#include "savegame.hpp"
#include "storage.hpp"
#include "mazeobject.hpp"
#include "player.hpp"
#include "state.hpp"
#include "intro.hpp"
#include "level.hpp"
#include "menu.hpp"
#include "screen.hpp"

#endif // HEADER_DUNGEON_XRAWLER_DUNGEON_XRAWLER_HPP
