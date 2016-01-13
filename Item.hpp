#ifndef ITEM_H
#define ITEM_H

#include "SFML/Graphics.hpp"

class Item {
    public:
        Item() {
            // sprite = NULL;
        }
    
        sf::Sprite sprite;
        
        bool canPass();
        bool isWall();
};

class Wall : public Item {
    public:
        Wall() {
            sf::Texture texture;
            texture.loadFromFile("images/Wall.png");
            sf::Sprite mysprite(texture);
            
            this->sprite = mysprite; // Item.sprite = Wall.mysprite 
        }
    
        bool canPass() { return false; }
        bool isWall()  { return true;  }
};

class Path : public Item {
    public:
        Path() {
            sf::Texture texture;
            texture.loadFromFile("images/Path.png");
            sf::Sprite mysprite(texture);
            
            this->sprite = mysprite; // Item.sprite = Path.mysprite
        }
    
        bool canPass() { return true;  }
        bool isWall()  { return false; }
};

#include "Item.cpp"

#endif // ITEM_H