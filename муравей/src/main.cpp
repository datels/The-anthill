#include <SFML/Graphics.hpp>
#include "anthill.hpp"
#include "enemy.hpp"
#include <ctime>
#include <iostream>


#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

struct Position 
{
    int x;
    int y;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

struct PositionHash {
    std::size_t operator()(const Position& pos) const 
    {
        return std::hash<int>()(pos.x) ^ (std::hash<int>()(pos.y) << 1);
    }
};

struct CellInfo {
    bool hasFood;       
    int foodAmount;     
    bool hasPalka;

};

class Ant {
public:
    Position getPosition() const { return currentPosition; }
    // мяу мяу

private:
    Position currentPosition;
    // мяу мяу
};

std::vector<Ant> ants;  
std::unordered_map<Position, CellInfo, PositionHash> positionMap;  

void processAnts() 
{
    for (Ant& ant : ants) 
    {
        Position antPos = ant.getPosition();
        auto it = positionMap.find(antPos);

        if (it != positionMap.end())
        {
            if (it->second.hasFood) 
            {
                // тут мы берем покушать себе
                std::cout << "Food found in the position ("
                    << antPos.x << ", " << antPos.y << ")\n";
            }
            if (it->second.hasPalka) 
            {
                // тут мы берем палку и тащим домой
                std::cout << "A stick found in the position ("
                    << antPos.x << ", " << antPos.y << ")\n";
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Ant Simulation");
    window.setFramerateLimit(60);
    sf::Clock food_and_sticks_Clock;


    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Anthill anthill;
    for (int i = 0; i < 10; ++i) {
        anthill.addAnt(std::make_shared<Ant>(std::rand() % 800, std::rand() % 600));
    }

    Enemy enemy(400.f, 300.f);

    while (window.isOpen()) {
        // Обработка событий через новый API
        while (auto event = window.pollEvent()) {
            // Проверка типа события через is()
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        if (food_and_sticks_Clock.getElapsedTime().asSeconds() >= 5.f) {
            //Добавь еду здесь (например, создать объект еды и добавить его в массив)
            for (int i = 0; i < 5; ++i) {
                anthill.generateFood(std::make_shared<Food>(std::rand() % 800, std::rand() % 600));
            }
            for (int i = 0; i < 5; ++i) {
                anthill.generateStick(std::make_shared<Stick>(std::rand() % 800, std::rand() % 600));
            }
            std::cout << "Добавлена еда на поле!\n";
            food_and_sticks_Clock.restart();
        }
        
        anthill.update();
        anthill.alertSoldiers(enemy);
        window.clear(sf::Color(0x22, 0x8B, 0x22));
        anthill.draw(window);
        enemy.draw(window);
        window.display();
    }

    return 0;
}
