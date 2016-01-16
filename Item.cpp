#include "Item.hpp"

// Item constructor
Item::Item() {
  
}

void Item::setLocation(int new_x, int new_y) {
  x = new_x;
  y = new_y;
}

// Wall constructor
Wall::Wall() {
  canPass = false;
  
  // Load sprite
  texture.loadFromFile("images/wall.jpg");
  sprite = new sf::Sprite(texture);
}

// Path constructor
Path::Path() {
  canPass = true;
  
  // Load sprite
  texture.loadFromFile("images/path.png");
  sprite = new sf::Sprite(texture);
}