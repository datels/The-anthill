#include "sticks.hpp"
Stick::Stick(float x, float y) {
    shape.setSize(sf::Vector2f(15.f, 5.f));
    shape.setFillColor(sf::Color(99,99,99));
     // Коричневый цвет
    sf::Vector2f position(x, y);
    shape.setPosition(position);
}
void Stick::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}