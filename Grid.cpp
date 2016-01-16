#include <iostream>
#include <fstream>

#include "Grid.hpp"

// Constructor
Grid::Grid()
{
	// Reset global variables
	this->startX = -1;
	this->startY = -1;
	this->endX   = -1;
	this->endY   = -1;
}

void Grid::loadFromFile(std::string &filename)
{
	// Temporary variables
	int x = 0, y = 0;
	
	// File layout
	const char PATH  = '.';
	const char WALL  = 'x';
	const char START = 'S';
	const char END   = 'E';
	
	
	// Open filestream for reading
	// NOTE You need .c_str() because C++ is a bitch
	std::ifstream file( filename.c_str() );
	
	// Parse file
	
	// Get next char from file
	char c;
	while ( file.get(c) ) {
		switch (c) {
			case WALL: {
				createWall(x, y);
				break;
			}
			
			case PATH: {
				createPath(x, y);
				break;
			}
			
			case START: {
				this->startX = x;
				this->startY = y;
				
				createPath(x, y);
				break;
			}
			
			case END: {
				this->endX = x;
				this->endY = y;
				
				createPath(x, y);
				break;
			}
			
			case '\n': {
				// Ignore newlines, as the pattern is a square
				break;
			}
			
			default: {
				// Unknown char found. Log
				std::cerr << "Invalid char '" << c << "' found in file!" << std::endl;
			}
		}
		
		// Next position
		++x;
		
		// The newline is the 5th character, so increase y when x>5
		if ( x > 5 ) {
			++y;
			x = 0;
		}
	}
	
	// Check if start and end values are set
	if (
		this->startX < 0 || this->startY < 0 ||
		this->endX   < 0 || this->endY   < 0
	) {
		std::cerr << "Start or finish not set!" << std::endl;
	}
}

// Check if given location is a path
bool Grid::canPass(int x, int y)
{
	return grid[x][y]->canPass;
}

// Create a wall at the given coordinates
void Grid::createWall(int x, int y)
{
	Wall *item = new Wall();
	
	item->setLocation(x, y);
	grid[x][y] = item;
}

// Create a path at the given coordinates
void Grid::createPath(int x, int y)
{
	Path *item = new Path();
	
	item->setLocation(x, y);
	grid[x][y] = item;
}

// Render all items on the window
void Grid::render(sf::RenderWindow &window)
{	
	// foreach Item item in grid:
	for (int x = 0; x < 5; ++x)   {
		for (int y = 0; y < 5; ++y) {
			Item *item = grid[x][y];
			
			// Check if item has a value
			if ( item != NULL ) {
				item->render( window );
				
			} else { // Something weird happened
				// Log failure
				std::cerr << "(" << x << ", " << y << ") does not contain any item!" << std::endl;
			}
		}
	}
}