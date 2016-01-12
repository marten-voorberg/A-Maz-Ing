# SMFL directory
SMFLDIR = ./SFML

# Output file
OUTPUTFILE = main

# Compiler
CPP = g++

# Compiler flags
CPPFLAGS= -Wall  -I $(SMFLDIR)/include  -I .  ${args}

# Libraries
LIBS = -L $(SMFLDIR)/lib   -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window


all: main

clean:
	rm -f *.o *.gch $(OUTPUTFILE) 

run: all
	@ export LD_LIBRARY_PATH=$(SMFLDIR)/lib
	./$(OUTPUTFILE)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp   Grid.hpp Grid.cpp   Item.hpp Item.cpp

main: main.o
	$(CPP) $(CPPFLAGS) -o $(OUTPUTFILE) *.o $(LIBS)
    