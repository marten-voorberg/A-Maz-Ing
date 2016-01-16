#include "SFML/Graphics.hpp"
#include <iostream>

// Include all classes
#include "Item.cpp"
#include "Grid.cpp"
#include "Player.cpp"

// Load grid from file
Grid grid("pattern.txt");

// Circle
sf::Sprite circle;

// Set the position of the circle
void setCirclePosition(Player &player) {
  circle.setPosition( player.getPositionX(), player.getPositionY() );
}


int main() {
  // Create window
  sf::RenderWindow renderWindow(sf::VideoMode(300, 300), "A-Maz-Ing");
  renderWindow.setFramerateLimit(20);
  
  // Create player
  Player player(grid.startX, grid.startY);
  
  // Load circle
  sf::Texture blackCircleTexture;
  blackCircleTexture.loadFromFile("images/blackcircle.png");
  
  circle = sf::Sprite(blackCircleTexture);
  
  // Position circle
  circle.setOrigin(sf::Vector2f (
    circle.getLocalBounds().width  / 2,
    circle.getLocalBounds().height / 2
  ));
  
  circle.setPosition (
    player.getPositionX() + player.getWidth()  * 1.5,
    player.getPositionY() + player.getHeight() * 1.5
  );
  
  
  // Window loop
  sf::Event event;
  while (renderWindow.isOpen()) {
    // Check for events
    while (renderWindow.pollEvent(event)) {
      
      // If window has to close
      if (event.type == sf::Event::Closed) {
        renderWindow.close();
      }
      
      // If a key is pressed
      else if (event.type == sf::Event::KeyPressed) {
        int key = event.key.code;
        
        // Arrow UP
        if ( key == sf::Keyboard::Up ) {
          player.moveUp(grid);
          setCirclePosition(player);
        }
        
        // Arrow DOWN
        else if ( key == sf::Keyboard::Down ) {
          player.moveDown(grid);
          setCirclePosition(player);
        }
        
        // Arrow LEFT
        else if ( key == sf::Keyboard::Left ) {
          player.moveLeft(grid);
          setCirclePosition(player);
        }
        
        // Arrow RIGHT
        else if ( key == sf::Keyboard::Right ) {
          player.moveRight(grid);
          setCirclePosition(player);
        }
        
        // Escape
        else if ( key == sf::Keyboard::Escape ) {
          renderWindow.close();
        }
        
        // Check if the player is at the finish point
        if ( player.x == grid.endX  &&  player.y == grid.endY ) {
          std::cout << "You have finished!" << std::endl;
        }
        
      }
    }
    
    // Clear window
    renderWindow.clear(sf::Color::Cyan);
    
    // Render all items in grid
    grid.render(renderWindow);
    
    // Render player
    player.render(renderWindow);
    
    // Render circle
    renderWindow.draw(circle);
    
    // Display all items
    renderWindow.display();
    
    // Sleep 100 ms
    sf::sleep( sf::milliseconds(100) );
  }
}
