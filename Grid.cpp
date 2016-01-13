#include <iostream>
#include <fstream>

#include "Grid.hpp"

Grid::Grid(std::string filename) {
  
  playerX = -1;
  playerY = -1;
  endX = -1;
  endY = -1;
  
  
  // Open filestream for reading
  std::ifstream file( filename.c_str() );
  
  char c;
  while( file.get(c) ) { // Get next char from file
    switch(c) {
      case 'x': // Wall
        this->grid[x][y] = new Wall();
        break;
      
      case 'o': // Path
        this->grid[x][y] = new Path(); 
        break;
      
      case 's': // Player starting point
        this->playerX = x;
        this->playerY = y;
        break;
      
      case 'e': // Finish point
        this->endX = x;
        this->endY = y;
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
  
  
  if(playerX<0 || playerY<0 || endX<0 || endY<0) {
    std::cerr << "Start or finish not set!" << std::endl;
  }
  
}

bool Grid::canPass(int x, int y) {
  return grid[x][y] -> canPass;
}