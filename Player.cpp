#include <iostream>

Player::Player() {
  playerSprite.loadFromFile("images/player.png");
  player.setTextureRect(playerDimension);
}

void Player::moveUp() {
 playerSprite.move(50, 0);
 //add animation
}
