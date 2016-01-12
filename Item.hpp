#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

class Item {
    public:
        Item(sf::Sprite&);
        
        bool canPass();
        bool isWall();
};

class Wall : public Item {
    public:
        sf::Texture texture;
	    texture.loadFromFile("images/Wall.png");
        sf::Sprite sprite(texture);
        Wall(sprite);
    
        bool canPass() { return false; }
        bool isWall()  { return true;  }
};

class Path : public Item {
    public:
        Path() {
            sf::Texture texture;
            texture.loadFromFile("images/Path.png");
            sf::Sprite sprite(texture);
            Item(sprite);
        }
    
        bool canPass() { return true;  }
        bool isWall()  { return false; }
};

#include "Item.cpp"

#endif // ITEM_H