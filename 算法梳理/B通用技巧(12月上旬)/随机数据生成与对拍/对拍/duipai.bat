@echo off
:loop
MakeData.exe
1.exe
2.exe
fc 1.out 2.out
if not errorlevel 1 goto loop
else echo YES
pause
:end
