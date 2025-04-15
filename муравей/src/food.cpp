#include "food.hpp"
#include <iostream>
sf::Texture Food::texture;
Food::Food(float x, float y):sprite(texture)
{
    sf::Vector2f position(x, y);
    sprite.setPosition(position);
    if (texture.getSize() == sf::Vector2u(0, 0))
    {

        if (!texture.loadFromFile("assets/IMG_6467.png"))
        {
            std::cerr << "Texture load failed\n";
            return;
        }
    }
    sprite.setTexture(texture);
    
}
void Food:: draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Vector2f Food:: getPosition() const {
    return sprite.getPosition();
}
