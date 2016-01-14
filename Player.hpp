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
}

#endif // PLAYER_H
