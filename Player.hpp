#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

#include "Grid.hpp"

class Player {
public:
  Player();
  
  // Position on grid
  int x, y;
  
  // sf variables
  sf::Sprite sprite;
  sf::Texture texture;
  sf::IntRect dimension;
  
  // Render player on window
  void render(sf::RenderWindow&);
  
  // Set location
  void setLocation(int x, int y);
  
  // Functions to move on grid
  void moveUp(Grid&);
  void moveDown(Grid&);
  void moveLeft(Grid&);
  void moveRight(Grid&);
  void afterMove();
  
  // Sprite values
  float getPositionX();
  float getPositionY();
  float getWidth();
  float getHeight();
};

#endif // PLAYER_H
