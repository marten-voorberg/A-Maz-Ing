@echo off


echo THIS DOES NOT WORK !!!



set SFML=./SFML-Windows-MinGW
set PATH=%PATH%;C:\MinGW\bin;%SFML%;%SFML%/lib;%SFML%/bin;%SFML%/include

echo Pre-compile Circle
g++ -Wall  -c Circle.hpp Circle.cpp   -I %SFML%/include

echo Pre-compile Item
g++ -Wall  -c Item.hpp Item.cpp  -I %SFML%/include

echo Pre-compile Grid
g++ -Wall  -c Grid.hpp Grid.cpp -I %SFML%/include

echo Pre-compile Player
g++ -Wall  -c Player.hpp Player.cpp -I %SFML%/include

echo Pre-compile main
g++ -Wall  -c main.cpp  -I %SFML%/include

echo Total compile
g++ -Wall  -o main main.o  -I %SFML%/include -L %SFML%/lib -lsfml-main -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window
