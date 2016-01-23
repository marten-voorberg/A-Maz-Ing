#ifndef GRID_H
#define GRID_H

#include "Item.hpp"

/// A class which generates a grid where you can place Item's on
class Grid {
public:
  Grid();
  
  /// Two-dimensional array with items
  Item* grid[5][5];
  
  // Coordinates of the start and end
  int startX, startY, endX, endY;
  
  /// Load pattern from file
  void loadFromFile( const std::string &filename );
  
  /// Check if the given location is a path
  bool canPass( int x, int y );
  
  /// Create Wall and add to grid
  void createWall ( int x, int y );
  
  /// Create Path and add to grid
  void createPath ( int x, int y );
  
  /// Render all Item's on window
  void render( sf::RenderWindow& );
};

#endif // GRID_H