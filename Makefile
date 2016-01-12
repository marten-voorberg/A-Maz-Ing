# SMFL directory
SMFLDIR = ./SFML

# Output file
OUTPUTFILE = main

# Compiler
CPP = g++

# Compiler flags
CPPFLAGS= -I $(SMFLDIR)/include  -I .

# Libraries
LIBS = -L $(SMFLDIR)/lib   -lsfml-audio  -lsfml-graphics  -lsfml-network  -lsfml-system  -lsfml-window


all: main
	
clean:
	rm -f *.o $(OUTPUTFILE)
	
run: all
	@ export LD_LIBRARY_PATH=$(SMFLDIR)/lib
	./$(OUTPUTFILE)
	
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp
	
main: main.o
	$(CPP) $(CPPFLAGS) -o $(OUTPUTFILE) main.o $(LIBS)