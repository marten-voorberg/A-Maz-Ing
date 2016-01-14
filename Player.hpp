#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  float getPositionX();
  float getPositionY();

private:
  float x, y;
  sf::Sprite playerSprite;
  sf::IntRect playerDimension;
};

#endif // PLAYER_H
