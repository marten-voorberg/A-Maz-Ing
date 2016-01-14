#include "SFML/Graphics.hpp"
#include <iostream>

#include "Grid.cpp"
Grid grid("pattern.txt");



/*
WIP
const int FPS = 25;
const int Skip = 1000 / FPS;
*/

sf::Sprite player, circle;
sf::IntRect playerDimension;

void moveUp() {
  
  // If destination is a wall
  if ( ! grid.canPass( grid.playerX, grid.playerY-1 ) ) {
    return;
  }
  
  --grid.playerY;
  
  playerDimension.top = 150;
  
  if (playerDimension.left == 150) {
    playerDimension.left = 0;
  } else {
    playerDimension.left += 50;
  }
  
  player.setTextureRect(playerDimension);
  player.move(0, -10);
  circle.setPosition(player.getPosition().x, player.getPosition().y);
}

void moveDown() {
  
  // If destination is a wall
  if ( ! grid.canPass( grid.playerX, grid.playerY+1 ) ) {
    return;
  }
  
  ++grid.playerY;
  
  playerDimension.top = 0;
  
  if (playerDimension.left == 150) {
    playerDimension.left = 0;
  } else {
    playerDimension.left += 50;
  }
  
  player.setTextureRect(playerDimension);
  player.move(0, 10);
  circle.setPosition(player.getPosition().x, player.getPosition().y);
}

void moveLeft() {
  
  // If destination is a wall
  if ( ! grid.canPass( grid.playerX-1, grid.playerY ) ) {
    return;
  }
  
  --grid.playerX;
  
  playerDimension.top = 50;
  
  if (playerDimension.left == 150) {
    playerDimension.left = 0;
  } else {
    playerDimension.left += 50;
  }
  
  player.setTextureRect(playerDimension);
  player.move(-10, 0);
  circle.setPosition(player.getPosition().x, player.getPosition().y);
}

void moveRight() {
  
  // If destination is a wall
  if ( ! grid.canPass( grid.playerX+1, grid.playerY ) ) {
    return;
  }
  
  ++grid.playerX;
  
  playerDimension.top = 100;
  
  if (playerDimension.left == 150) {
    playerDimension.left = 0;
  } else {
    playerDimension.left += 50;
  }
  
  player.setTextureRect(playerDimension);
  player.move(10, 0);
  circle.setPosition(player.getPosition().x, player.getPosition().y);
}


int main() {
  sf::RenderWindow renderWindow(sf::VideoMode(300, 300), "Sprite Demo");
  renderWindow.setFramerateLimit(20);
  
  Player playerClass();
  sf::Sprite player = playerClass.playerSprite;
  
  sf::Texture blackCircleTexture;
  blackCircleTexture.loadFromFile("images/blackcircle.png");
  
  circle = sf::Sprite(blackCircleTexture);
  
  circle.setOrigin(sf::Vector2f (
    circle.getLocalBounds().width  / 2,
    circle.getLocalBounds().height / 2
  ));
  
  circle.setPosition (
    player.getPosition().x + player.getLocalBounds().width  + player.getLocalBounds().width / 2,
    
    //                                                                @Marten  ------v  .width, niet .height ?
    player.getPosition().y + player.getLocalBounds().height + player.getLocalBounds().width / 2
  );
  
  sf::Event event;
  while (renderWindow.isOpen()) {
    /*
      next_game_tick += SKIP_TICKS;
      sleep_time = next_game_tick - GetTickCount();
      if (sleep_time >= 0) {
        sleep(sleep_time);
      } else {
        // Shit, we are running behind!
      }
    */
    
    while (renderWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        renderWindow.close();
      }
      
      else if (event.type == sf::Event::KeyPressed) {
        int key = event.key.code;
        
        #define LOG std::cout << grid.playerX << ", " << grid.playerY << std::endl;
        
        if ( key == sf::Keyboard::Up ) {
          moveUp();
          LOG;
        }
        else if ( key == sf::Keyboard::Down ) {
          moveDown();
          LOG;
        }
        else if ( key == sf::Keyboard::Left ) {
          moveLeft();
          LOG;
        }
        else if ( key == sf::Keyboard::Right ) {
          moveRight();
          LOG;
        }
        
        if(grid.isFinished()) {
          std::cout << "You have finished!" << std::endl;
        }
        
      }
    }
    
    renderWindow.clear(sf::Color::White);
    renderWindow.draw(player);
    renderWindow.draw(circle);
    renderWindow.display();
    
    sleep(100);
  }
}
