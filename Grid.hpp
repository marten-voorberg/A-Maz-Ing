#ifndef GRID_H
#define GRID_H

#include "Item.hpp"

class Grid {
public:
  Grid();
  
  // Grid with items
  Item* grid[5][5];
  
  // Coordinates of the start and end
  int startX, startY, endX, endY;
  
  // Load pattern from file
  void loadFromFile( const std::string &filename );
  
  // Check if the given location is a path
  bool canPass( int x, int y );
  
  // Functions to add objects to grid
  void createWall ( int x, int y );
  void createPath ( int x, int y );
  
  // Render all items on window
  void render( sf::RenderWindow& );
};

#endif // GRID_H