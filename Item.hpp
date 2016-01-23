#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

/// A class representing an item on the Grid
class Item {
public:
  Item();
  
  // Position on Grid
  int x, y;
  
  /// Value if you can pass this item
  bool canPass;
  
  // sf variables
  sf::Texture texture;
  sf::Sprite  sprite;
  
  /// Set location on Grid for item
  void setLocation( int x, int y );
  
  /// Render item
  void render( sf::RenderWindow& );
};

/// A class representing a wall on the Grid
class Wall : public Item {
public:
  Wall();
};

/// A class representing a path on the Grid
class Path : public Item {
public:
  Path();
};

#endif // ITEM_H
