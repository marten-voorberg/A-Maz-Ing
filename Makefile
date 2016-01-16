# Compiler
CPP = g++

# SFML directory (Doesn't work yet, this is here for decoration)
SFMLDIR = ./SFML

# Compiler flags
#		-I $(SFMLDIR)/include
CPPFLAGS = -Wall  -std=gnu++11  -I .  ${args}

# Libraries
#		-L $(SFMLDIR)/lib
LIBS =  -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window

# Output file
OUTPUTFILE = main

all: main

# Remove all compiled files
# (Usually ran before commiting, or when rebuilding)
clean:
	rm -f *.o *.gch $(OUTPUTFILE) 

# Rebuild project
rebuild:
	make clean
	make all

# Run created project
#		@ export LD_LIBRARY_PATH=$(SMFLDIR)/lib
run:
	./$(OUTPUTFILE)


# Actually building files below here

# Item class
Item.o: Item.hpp Item.cpp
	$(CPP) $(CPPFLAGS) -c Item.hpp Item.cpp

# Grid class (Requires Item class)
Grid.o: Grid.hpp Grid.cpp  Item.o
	$(CPP) $(CPPFLAGS) -c Grid.hpp Grid.cpp

# Player class (Requires Grid class)
Player.o: Player.hpp Player.cpp  Grid.o
	$(CPP) $(CPPFLAGS) -c Player.hpp Player.cpp

# Main class (Requires Item class, Grid class, and Player class)
main.o: main.cpp  Item.o Grid.o Player.o
	$(CPP) $(CPPFLAGS) -c main.cpp

# Actual program (Requires Main class)
main: main.o
	$(CPP) $(CPPFLAGS) main.o -o $(OUTPUTFILE)  $(LIBS)
    