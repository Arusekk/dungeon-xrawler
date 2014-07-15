@echo off
type *.cpp >TEMPF125
rename TEMPF125 TEMPF125.cpp
start TEMPF125.cpp
pause
del TEMPF125.cpp
