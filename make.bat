@echo off

set SFML=./SFML-Windows-VS
set PATH=%PATH%;C:\MinGW\bin


echo THIS DOES NOT WORK !!! (yet)


:pre-compile
echo Pre-compiling...
g++ -Wall -c *.cpp *.hpp -I %SFML%/include

:compile
echo Compiling...
g++ -Wall -o main -L %SFML%/lib/ *.o -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window


echo Press a key to close...
pause > nul