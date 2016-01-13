#include "Item.hpp"

Item::Item() {
  
}

Wall::Wall() {
  this->canPass = false; // Item.canPass
  
  sf::Texture texture;
  texture.loadFromFile("images/Wall.png");
  sf::Sprite mysprite(texture);
  
  this->sprite = mysprite; // Item.sprite = Wall.mysprite 
}

Path::Path() {
  this->canPass = true; // Item.canPass
  
  sf::Texture texture;
  texture.loadFromFile("images/Path.png");
  sf::Sprite mysprite(texture);

  this->sprite = mysprite; // Item.sprite = Path.mysprite
}