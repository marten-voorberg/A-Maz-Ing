#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

// Main Item class
class Item {
public:
  Item();
  
  // Position on grid
  int x, y;
  
  // Value if you can pass this item
  bool canPass;
  
  // Sf variables
  sf::Sprite *sprite;
  sf::Texture texture;
  
  // Set location on grid for item
  void setLocation(int x, int y);
};

// Wall class, which is a subclass of Item
class Wall : public Item {
public:
  Wall();
};

// Path class, which is a subclass of Path
class Path : public Item {
public:
  Path();
};

#endif // ITEM_H
