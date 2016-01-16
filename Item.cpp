#include <iostream>

#include "Item.hpp"

// Item constructor
Item::Item()
{
	
}

void Item::setLocation(int new_x, int new_y)
{
	this->x = new_x;
	this->y = new_y;
	
	this->sprite.setPosition( 50 * this->x, 50 * this->y );
}

void Item::render(sf::RenderWindow &window)
{
	window.draw( this->sprite );
}



// Wall constructor
Wall::Wall()
{
	this->canPass = false;
	
	// Load sprite
	this->texture .loadFromFile ( "./images/wall.jpg" );
	this->sprite  = sf::Sprite  ( this->texture       );
}

// Path constructor
Path::Path()
{
	this->canPass = true;
	
	// Load sprite
	this->texture .loadFromFile ( "./images/path.jpg" );
	this->sprite  = sf::Sprite  ( this->texture       );
}