#include "Circle.hpp"

// Circle constructor
Circle::Circle()
{
	this->texture .loadFromFile ( "./images/blackcircle.png" );
	this->sprite  = sf::Sprite  ( this->texture );
	
	// Position circle
	this->sprite.setOrigin( sf::Vector2f (
		this->sprite.getLocalBounds().width  / 2,
		this->sprite.getLocalBounds().height / 2
	));
}

// Set sprite position
void Circle::setPosition(float x, float y)
{
  this->sprite.setPosition(x, y);
}

// Render on window
void Circle::render(sf::RenderWindow &window)
{
  window.draw( this->sprite );
}