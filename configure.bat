@echo off

CD >place.txt
SET /P place=<place.txt
DEL place.txt

SET infor=[INFOR]
SET succe=[SUCCE]
SET quest=[QUEST]
SET fatal=[FATAL]

ECHO %infor% Looking for \`make' ...
SET make32="%PROGRAMFILES%\GnuWin32\bin\make.exe"
SET make64="%PROGRAMFILES(X86)%\GnuWin32\bin\make.exe"
SET make=%make32%
IF NOT DEFINED orgPATH SET orgPATH=%PATH%
IF EXIST "%PROGRAMFILES(X86)%" (
 SET make=%make64%
 SET PATH=%orgPATH%;%PROGRAMFILES(X86)%\GnuWin32\bin
) ELSE (
 SET PATH=%orgPATH%;%PROGRAMFILES%\GnuWin32\bin
)
SET PATH=%PATH%;C:\Dev-Cpp\bin;%place%\windowsstuff

:AGAIN
IF EXIST %make% GOTO KK
ECHO.
ECHO %infor% Please install GnuWin32 make with default settings.
ECHO %infor% When installed, press any key.
PAUSE
GOTO AGAIN

:KK
ECHO %succe% Found make! Yay!
make windows=T
