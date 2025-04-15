#include "sticks.hpp"
#include <iostream>
sf::Texture Stick::texture;
Stick::Stick(float x, float y):sprite(texture) {
    sf::Vector2f position(x, y);
    sprite.setPosition(position);
    if (texture.getSize() == sf::Vector2u(0, 0))
    {

        if (!texture.loadFromFile("assets/stick.png"))
        {
            std::cerr << "Texture load failed\n";
            return;
        }
    }
    sprite.setTexture(texture);
    
    
     // Коричневый цвет
    sprite.setPosition(position);
}
void Stick::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}