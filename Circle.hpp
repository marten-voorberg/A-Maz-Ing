#ifndef CIRCLE_H
#define CIRCLE_H

#include "SFML/Graphics.hpp"

/// A class which renders the black circle around the Player
class Circle {
public:
  Circle();
  
  // sf variables
  sf::Texture texture;
  sf::Sprite  sprite;
  
  /// Set position of sprite
  void setPosition(int x, int y);
  
  /// Render circle on window 
  void render(sf::RenderWindow&);
};

#endif // CIRCLE_H