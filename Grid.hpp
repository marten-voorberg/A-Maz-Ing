#ifndef GRID_H
#define GRID_H

#include "Item.hpp"

class Grid {
    public:
        Grid(std::string);
        
        Item* grid[5][5];
        
        int playerX, playerY;
        
    private:
        int x,y;
};

#endif // GRID_H