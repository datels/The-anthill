#ifndef STICK_HPP
#define STICK_HPP
#include <SFML/Graphics.hpp>
class Stick: public std::enable_shared_from_this<Stick> {
    public:
        Stick(float x, float y);
        void draw(sf::RenderWindow& window) const;
        sf::Vector2f getPosition() const;
    
    private:
    static sf::Texture texture;
    sf::Sprite sprite;
    };
#endif