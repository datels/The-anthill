#include "food.hpp"
#include "map.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
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
    //sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10)));
    
}void Food:: draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

// void Food:: registerCircularBoundary(sf::Vector2f center, int radius, Food* obj) {
//     for (float angle = 0; angle < 2 * M_PI; angle += 0.1f) {
//         float x = static_cast<int>(center.x + radius * std::cos(angle));
//         float y = static_cast<int>(center.y + radius * std::sin(angle));
//         positionMap[Position{x,y}].ptr = obj;
//         positionMap[Position{x,y}].hasFood = true;
//     }
// }
void Food::eat()
{
    this->~Food();
    std::cout << "Food eaten\n";
}

sf::Vector2f Food:: getPosition() const {
    return sprite.getPosition();
}
