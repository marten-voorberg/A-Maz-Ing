#include <iostream>

#include "Item.hpp"

// Item constructor
Item::Item() {
  
}

void Item::setLocation(int new_x, int new_y) {
  x = new_x;
  y = new_y;
  
  if ( sprite != NULL ) {
    // Set position of sprite
    sprite->setPosition( 50*x, 50*y );
  } else {
    // No sprite set ?! Stupid user
    std::cerr << "You're working with an Item class without a sprite" << std::endl;
    std::cerr << "You should first add a sprite, or use the Wall or Path class" << std::endl;
  }
}

// Wall constructor
Wall::Wall() {
  canPass = false;
  
  // Load sprite
  texture.loadFromFile("./images/wall.jpg");
  sprite = new sf::Sprite(texture);
}

// Path constructor
Path::Path() {
  canPass = true;
  
  // Load sprite
  texture.loadFromFile("./images/path.jpg");
  sprite = new sf::Sprite(texture);
}