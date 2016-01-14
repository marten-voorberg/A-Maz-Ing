#include <iostream>

Player::Player() {
  sf::Texture playerTexture;
  playerTexture.loadFromFile("images/player.png");
  playerDimension = sf::IntRect(50, 0, 50, 50);
  playerSprite = sf::Sprite(playerTexture, playerDimension);
}

void Player::moveUp() {
 playerSprite.move(50, 0);
 //add animation
}
