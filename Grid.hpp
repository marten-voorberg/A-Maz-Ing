#ifndef GRID_H
#define GRID_H

#include "Item.cpp"

class Grid {
public:
  Grid(std::string);
  
  bool canPass(int, int);
  
  Item* grid[5][5];
  
  int playerX, playerY;
  
private:
  int x=0, y=0;
};

#endif // GRID_H