#include "anthill.hpp"

Anthill::Anthill(){
    shape.setRadius(20.f);
    shape.setFillColor(sf::Color(139, 69, 19));
    shape.setPosition(sf::Vector2f(400.f, 300.f));
}
void Anthill::update() {
    for (auto& ant : ants){ 
        ant->update();
        
    }
    
}

void Anthill::draw(sf::RenderWindow& window) {
    for (auto& ant : ants) ant->draw(window);
    window.draw(shape);
    for (auto& food : foods) food->draw(window);
    for (auto& stick : sticks) stick->draw(window);
}

void Anthill::addAnt(std::shared_ptr<Ant> ant) {
    ants.push_back(ant);
}

void Anthill::generateFood(std::shared_ptr<Food> food)
{
    foods.push_back(food);
}

void Anthill::generateStick(std::shared_ptr<Stick> stick)
{
    sticks.push_back(stick);
}

// void Anthill::addFood(int amount)
// {
//     if (food ++ <= foodCapacity) {
//         food ++;
//     }
// }

// void Anthill::addSticks(int amount)
// {
//     if (countSticks ++ <= sticksCapacity) {
//         countSticks ++;
//     }
// }




void Anthill::alertSoldiers(const Enemy& enemy) {
    bool alerted = false;

    for (auto& ant : ants) {
        if (ant->getRoleName() == "Soldier" && ant->isNear(enemy.getPosition(), 100.f)) {
            soldierNotifier.notifyAll();
            alerted = true;
            break;
        }
    }

    if (alerted) {
        for (auto& ant : ants) {
            if (ant->getRoleName() == "Soldier") {
                ant->subscribeToNotifier(soldierNotifier);
            }
        }
    }
}


