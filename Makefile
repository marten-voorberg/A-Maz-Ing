# SMFL directory
SMFLDIR = ./SFML

# Output file
OUTPUTFILE = main

# Compiler
CPP = g++

# Compiler flags
CPPFLAGS= -Wall  -I .  ${args}

# Libraries
LIBS =  -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window


all: main

clean:
	rm -f *.o *.gch $(OUTPUTFILE) 

run: main
	@ export LD_LIBRARY_PATH=$(SMFLDIR)/lib
	./$(OUTPUTFILE)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -I $(SMFLDIR)/include -c main.cpp   Grid.hpp Grid.cpp   Item.hpp Item.cpp

main: main.o
	$(CPP) $(CPPFLAGS) main.o -o $(OUTPUTFILE)  $(LIBS) # -L $(SMFLDIR)/lib
    