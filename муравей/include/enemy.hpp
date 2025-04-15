#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float x, float y);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    void moveRandomly();

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif