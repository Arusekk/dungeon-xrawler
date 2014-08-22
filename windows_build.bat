@echo off
title Rough draft of build on Windows
echo In my opinion it doesn't work, but feel free to try.
pause

cd src
type *.cpp >../TEMPF125
cd ..
rename TEMPF125 TEMPF125.cpp
start TEMPF125.cpp
ping -n 2 127.1.2.3 >nul
del TEMPF125.cpp
