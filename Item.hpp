#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

// Main Item class
class Item {
public:
  Item();
  
  bool canPass;
  sf::Sprite sprite;
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