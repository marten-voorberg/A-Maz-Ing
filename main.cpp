#include "SFML/Graphics.hpp"
#include <iostream>

#include "Grid.cpp"
Grid grid("pattern.txt");

// Cross-platform shit
#ifdef _WINDOWS

  // Windows: Sleep function = Sleep(ms)
  #include <windows.h>
  void sleep(int ms) {
    Sleep(ms);
  }
  
#else

  // Linux: Sleep function = usleep(ms * 1000)
  #include <unistd.h>
  void sleep(int ms) {
    usleep(ms * 1000);
  }
  
#endif



/*
WIP
const int FPS = 25;
const int Skip = 1000 / FPS;
*/

int main() {
  sf::RenderWindow renderWindow(sf::VideoMode(300, 300), "Sprite Demo");
  renderWindow.setFramerateLimit(20);
  sf::Event event;
  
  sf::Texture guyTexture;
  guyTexture.loadFromFile("images/200by200.png");
  
  sf::Texture blackCircleTexture;
  blackCircleTexture.loadFromFile("images/blackcircle.png");
  
  sf::IntRect playerDimension(50, 0, 50, 50);
  sf::Sprite player(guyTexture, playerDimension);
  player.setPosition(150, 150);
  
  sf::Sprite circle(blackCircleTexture);
  
  circle.setOrigin(sf::Vector2f (
    circle.getLocalBounds().width  / 2,
    circle.getLocalBounds().height / 2
  ));
  
  circle.setPosition (
    player.getPosition().x + player.getLocalBounds().width  + player.getLocalBounds().width / 2,
    
    //                                                                @Marten  ------v  .width, niet .height ?
    player.getPosition().y + player.getLocalBounds().height + player.getLocalBounds().width / 2
  );
  
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
      
      if (event.type == sf::Event::KeyPressed) {
        
        if (event.key.code == sf::Keyboard::Up) {
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
        
        else if (event.key.code == sf::Keyboard::Down) {
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
        
        else if (event.key.code == sf::Keyboard::Left) {
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
        
        else if (event.key.code == sf::Keyboard::Right) {
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
      }
    }
    
    renderWindow.clear(sf::Color::White);
    renderWindow.draw(player);
    renderWindow.draw(circle);
    renderWindow.display();
    
    sleep(100);
  }
}
