#include "Circle.hpp"

Circle::Circle()
{
	this->texture .loadFromFile ( "./images/blackcircle.png" );
	this->sprite  = sf::Sprite  ( this->texture );
	
	// Position circle
	sprite.setOrigin( sf::Vector2f (
		sprite.getLocalBounds().width  / 2,
		sprite.getLocalBounds().height / 2
	));
}

// Set sprite position
void Circle::setPosition(int x, int y)
{
  this->sprite.setPosition(x, y);
}

// Render on window
void Circle::render(sf::RenderWindow &window)
{
  window.draw( this->sprite );
}