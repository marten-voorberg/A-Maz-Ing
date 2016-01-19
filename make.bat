@echo off

"../../MinGW/bin/g++" -Wall  -I ./SFML/include  -I .   -c Item.hpp Item.cpp
"../../MinGW/bin/g++" -Wall  -I ./SFML/include  -I .   -c Grid.hpp Grid.cpp
"../../MinGW/bin/g++" -Wall  -I ./SFML/include  -I .   -c main.cpp
"../../MinGW/bin/g++" -Wall  -I ./SFML/include  -I .    main.o -o main  -L ./SFML/lib -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window
