@echo off
SET force=0
for %%x in (%*) do (
 if "%1"=="-f" (
  SET force=1
 ) ELSE (
  IF "%force%"=="1" (
   echo>%1
  )
  del %1
 )
 shift
)