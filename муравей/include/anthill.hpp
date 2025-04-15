#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <vector>
#include <memory>
#include "ant.hpp"
#include "sticks.hpp"
#include "food.hpp"
#include "enemy.hpp"
#include "notifier.hpp"

class Anthill
{
public:
    Anthill();
    void update();
    void draw(sf::RenderWindow &window);
    void addAnt(std::shared_ptr<Ant> ant);
    void alertSoldiers(const Enemy &enemy);
    void generateFood(std::shared_ptr<Food> food);
    void generateStick(std::shared_ptr<Stick> stick);
    //void addFood(int amount);//?????????????????????
    //void addSticks(int amount);//?????????????????????
    //void addAnts(int amount);//?????????????????????
    //void addSize(int amount);//?????????????????????
    // void addFoodCapacity(int amount);
    // void addSticksCapacity(int amount);
    // void addAntsCapacity(int amount);
    // void dropSize();
    // void dropFood();
    // void dropSticks();


private:
    std::vector<std::shared_ptr<Ant>> ants;
    std::vector<std::shared_ptr<Food>> foods;
    std::vector<std::shared_ptr<Stick>> sticks;
    Notifier soldierNotifier;
    sf::CircleShape shape;
    static int food, foodCapacity, antsCapacity, size, countSticks, sticksCapacity;
};

#endif