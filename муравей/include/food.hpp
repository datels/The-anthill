#ifndef FOOD_HPP
#define FOOD_HPP
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Food : public std::enable_shared_from_this<Food> {
public:
    Food(float x, float y);
    ~Food() = default;
    void draw(sf::RenderWindow& window) const;
    void eat();
    //void registerCircularBoundary(sf::Vector2f center, int radius, Food* obj);
    sf::Vector2f getPosition() const;

private:
    static sf::Texture texture;
    sf::Sprite sprite;
};

#endif