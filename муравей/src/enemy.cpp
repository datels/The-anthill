#include "enemy.hpp"
#include <cstdlib>

Enemy::Enemy(float x, float y) {
    shape.setRadius(8.f);
    shape.setFillColor(sf::Color::Red);
    sf::Vector2f position(x, y);
    shape.setPosition(position);
    velocity = sf::Vector2f((std::rand() % 3 - 1) * 1.0f, (std::rand() % 3 - 1) * 1.0f);
}

void Enemy::draw(sf::RenderWindow& window) {
    moveRandomly();
    window.draw(shape);
}

sf::Vector2f Enemy::getPosition() const {
    return shape.getPosition();
}

void Enemy::moveRandomly() {
    shape.move(velocity);
    if (std::rand() % 100 < 10) {
        velocity = sf::Vector2f((std::rand() % 3 - 1) * 1.0f, (std::rand() % 3 - 1) * 1.0f);
    }
}

