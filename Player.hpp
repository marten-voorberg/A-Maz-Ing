#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

#include "Grid.hpp"

/// The player who walks across the Grid
class Player {
public:
  Player();
  
  // Position on Grid
  int x, y;
  
  // sf variables
  sf::Texture texture;
  sf::IntRect dimension;
  sf::Sprite  sprite;
  
  /// Set location on Grid
  void setLocation( int x, int y );
  
  /// Move up on the Grid
  void moveUp    ( Grid& );
  
  /// Move down on the Grid
  void moveDown  ( Grid& );
  
  /// Move left on the Grid
  void moveLeft  ( Grid& );
  
  /// Move right on the Grid
  void moveRight ( Grid& );
  
  /// Called after the player has moved
  void afterMove ();
  
  /// Render player on window
  void render( sf::RenderWindow& );
  
  // Sprite values
  float getPositionX ();
  float getPositionY ();
  float getWidth     ();
  float getHeight    ();
};

#endif // PLAYER_H
