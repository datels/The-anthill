#ifndef STICK_HPP
#define STICK_HPP
#include <SFML/Graphics.hpp>
class Stick {
    public:
        Stick(float x, float y);
        void draw(sf::RenderWindow& window) const;
        sf::Vector2f getPosition() const;
    
    private:
        sf::RectangleShape shape;
    };
#endif