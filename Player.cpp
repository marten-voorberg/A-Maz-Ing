#include <iostream>

#include "Player.hpp"

// Constructor
Player::Player()
{
	// Load texture
	texture   .loadFromFile ( "./images/player.png" );
	dimension = sf::IntRect ( 50, 0, 50, 50      );
	sprite    = sf::Sprite  ( texture, dimension );
}

void Player::setLocation(int new_x, int new_y)
{
	// Set location
	x = new_x;
	y = new_y;
}

void Player::moveUp(Grid &grid)
{
	// Check bounds
	if ( y == 0 ) {
		return;
	}
	
	// If destination is a wall
	if ( ! grid.canPass( x, y - 1 ) ) {
		return;
	}
	
	// Move up
	--y;
	
	// Set dimensions
	dimension.top = 150;
	
	if (dimension.left == 150) {
		dimension.left = 0;
	} else {
		dimension.left += 50;
	}
	
	// Update sprite
	sprite.setTextureRect( dimension );
	sprite.move( 0, -10 );
	
	// Do the aftermoves
	afterMove();
}

void Player::moveDown(Grid &grid)
{
	// Check bounds
	if ( y == 4 ) {
		return;
	}
	
	// If destination is a wall
	if ( ! grid.canPass( x, y + 1 ) ) {
		return;
	}
	
	// Move down
	++y;
	
	// Set dimensions
	dimension.top = 0;
	
	if (dimension.left == 150) {
		dimension.left = 0;
	} else {
		dimension.left += 50;
	}
	
	// Update sprite
	sprite.setTextureRect( dimension );
	sprite.move( 0, 10 );
	
	// Do the aftermoves
	afterMove();
}

void Player::moveLeft(Grid &grid)
{
	
	// Check bounds
	if ( x == 0 ) {
		return;
	}
	
	// If destination is a wall
	if ( ! grid.canPass( x - 1, y ) ) {
		return;
	}
	
	// Move left
	--x;
	
	// Set dimensions
	dimension.top = 50;
	
	if (dimension.left == 150) {
		dimension.left = 0;
	} else {
		dimension.left += 50;
	}
	
	// Update sprite
	sprite.setTextureRect( dimension );
	sprite.move( -10, 0 );
	
	// Do the aftermoves
	afterMove();
}

void Player::moveRight(Grid &grid)
{
	// Check bounds
	if ( x == 4 ) {
		return;
	}
	
	// Check destination for wall
	if ( ! grid.canPass( x + 1, y ) ) {
		return;
	}
	
	// Move right
	++x;
	
	// Set dimensions
	dimension.top = 100;
	
	if (dimension.left == 150) {
		dimension.left = 0;
	} else {
		dimension.left += 50;
	}
	
	// Update sprite
	sprite.setTextureRect( dimension );
	sprite.move( 10, 0 );
	
	// Do the aftermoves
	afterMove();
}

void Player::afterMove()
{
	// Log where the player is
	std::cout << "Player: (" << x << ", " << y << ")" << std::endl;
}

// Render on window
void Player::render(sf::RenderWindow &window)
{
	window.draw( sprite );
}

// Get sprite positions
float Player::getPositionX()
{
	return sprite.getPosition().x;
}

float Player::getPositionY()
{
	return sprite.getPosition().y;
}

// Get sprite dimensions
float Player::getWidth()
{
	return sprite.getLocalBounds().width;
}

float Player::getHeight()
{
	return sprite.getLocalBounds().height;
}