#ifndef GRID_H
#define GRID_H

#include "Item.cpp"

class Grid {
public:
  Grid(std::string);
  
  bool canPass(int, int);
  inline bool isFinished() {
    return playerX==endX && playerY==endY;
  }
  
  Item* grid[5][5];
  
  int playerX, playerY, endX, endY;
  
private:
  int x=0, y=0;
};

#endif // GRID_H