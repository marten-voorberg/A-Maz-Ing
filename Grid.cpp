#include <iostream>
#include <fstream>

#include "Grid.hpp"

void createPath(Grid *grid, int x, int y) {
  Path* item = new Path();
  item.x = 50 * x;
  item.y = 50 * y;
  grid->grid[x][y] = item;
}


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
        Wall* item = new Wall();
        item.x = 50 * x;
        item.y = 50 * y;
        this->grid[x][y]=item;

        break;

      case 'o': // Path
        createPath(this, x, y);

        break;

      case 's': // Player starting point
        this->playerX = x;
        this->playerY = y;

        createPath(this, x, y);

        break;

      case 'e': // Finish point
        this->endX = x;
        this->endY = y;

        createPath(this, x, y);

        break;

      case '\n':
        // Ignore newlines, as it's a square
        break;

      default:
        std::cerr << "Invalid char '" << c << "' found in file!" << std::endl;
    }

    ++x;
    if ( x >= 5 ) {
      ++y;
      x=0;
    }
  }


  if ( playerX < 0 || playerY < 0 || endX < 0 || endY < 0 ) {
    std::cerr << "Start or finish not set!" << std::endl;
  }

}

bool Grid::canPass(int x, int y) {
  return grid[x][y] -> canPass;
}
