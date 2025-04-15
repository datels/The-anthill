#ifndef FOOD_HPP
#define FOOD_HPP
#include <SFML/Graphics.hpp>


class Food {
public:
    Food(float x, float y);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;

private:
    sf::CircleShape shape;
};

#endif