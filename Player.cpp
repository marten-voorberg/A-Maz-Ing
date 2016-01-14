#include <iostream>

Player::Player() {
  playerSprite.loadFromFile("images/player.png");
}

void Player::moveUp() {
 playerSprite.move(50, 0);
 player.setTextureRect(playerDimension);
 //add animation
}
