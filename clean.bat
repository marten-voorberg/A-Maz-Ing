@echo off

echo Cleaning root
del *.o *.gch main

echo Cleaning project
cd A-Maz-Ing

rmdir /S /Q Debug
rmdir /S /Q x64


echo Press a key to close...
pause > nul