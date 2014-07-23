@echo off
title Rough draft of build on Windows
echo This doesn't work
pause

cd src
type *.cpp >TEMPF125
rename TEMPF125 TEMPF125.cpp
start TEMPF125.cpp
del TEMPF125.cpp
