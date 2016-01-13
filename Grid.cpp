#include <iostream>
#include <fstream>

#include "Grid.hpp"

Grid::Grid(std::string filename) {
  // Open filestream for reading
  std::ifstream file( filename.c_str() );
  
  char c;
  while( file.get(c) ) { // Get next char from file
    switch(c) {
      case 'x': // Wall
        this->grid[x][y] = new Wall();
        break;
      
      case '-': // Path
        this->grid[x][y] = new Path(); 
        break;
      
      case 'o': // Player starting point
        this->playerX = x;
        this->playerY = y;
        break;
      
      case '\n':
        // Ignore newlines, as it's a square
        break;
      
      default:
        std::cerr << "Invalid char '" << c << "' found in file!" << std::endl;
    }
    
    ++x;
    if( x >= 5 ) {
      ++y;
      x=0;
    }
  }
}

bool Grid::canPass(int x, int y) {
  return grid[x][y] -> canPass;
}