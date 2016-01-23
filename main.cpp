#include <iostream>

#include "SFML/Graphics.hpp"

// Include all classes
#include "Circle.hpp"
#include "Item.hpp"
#include "Grid.hpp"
#include "Player.hpp"

// Items
Grid	grid;
Player	player;
Circle	circle;

// Set the position of the circle
void setCirclePosition(Player &player)
{
	circle.setPosition( player.getPositionX(), player.getPositionY() );
}

// Check if player is at the end location
// NOTE inline is used for small functions doing a single task to speed up the process
inline bool isFinished()
{
	return player.x == grid.endX  &&  player.y == grid.endY;
}

int main()
{
	// Create window
	sf::RenderWindow window( sf::VideoMode(250, 250), "A-Maz-Ing" );
	
	window.setFramerateLimit( 20 );
	
	// Load grid
	grid.loadFromFile( "./Patterns/level-0.txt" );
	
	// Set location of player on the start location from the grid
	player.setLocation( grid.startX, grid.startY );
	
	
	circle.setPosition(
		player.getPositionX() + player.getWidth() * 1.5,
		player.getPositionY() + player.getHeight() * 1.5
	);
	
	
	// Window loop
	while (window.isOpen()) {
		
		// Check for events
		sf::Event event;
		while (window.pollEvent( event )) {
			
			// If window has to close
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			// If a key is pressed
			else if (event.type == sf::Event::KeyPressed) {
				int key = event.key.code;
				
				// Arrow UP
				if (key == sf::Keyboard::Up) {
					player.moveUp( grid   );
					setCirclePosition( player );
				}
				
				// Arrow DOWN
				else if (key == sf::Keyboard::Down) {
					player.moveDown( grid   );
					setCirclePosition( player );
				}
				
				// Arrow LEFT
				else if (key == sf::Keyboard::Left) {
					player.moveLeft( grid   );
					setCirclePosition( player );
				}
				
				// Arrow RIGHT
				else if (key == sf::Keyboard::Right) {
					player.moveRight( grid   );
					setCirclePosition( player );
				}
				
				// Escape
				else if (key == sf::Keyboard::Escape) {
					window.close();
				}
				
				// CHEAT (RShift + C)
				else if (
					sf::Keyboard::isKeyPressed( sf::Keyboard::RShift ) &&
					sf::Keyboard::isKeyPressed( sf::Keyboard::C      )
				) {
					
					player.setLocation( grid.endX, grid.endY );
				}
				
				// Check if the player is at the finish
				if (isFinished()) {
					std::cout << "You have finished!" << std::endl;
					// TODO Next level
				}
				
			}
		}
		
		// Clear window
		window.clear( sf::Color::White );
		
		// Render all items in grid
		grid.render( window );
		// Render player
		player.render( window );
		// Render circle
		circle.render( window );
		
		// Display all items
		window.display();
		
		// Sleep 100 ms
		sf::sleep( sf::milliseconds( 100 ) );
	}
}
