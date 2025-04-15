#include "food.hpp"

Food::Food(float x, float y)
{
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Yellow);
    sf::Vector2f position(x, y);
    shape.setPosition(position);
    
}
void Food:: draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Food:: getPosition() const {
    return shape.getPosition();
}
