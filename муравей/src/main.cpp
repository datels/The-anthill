#include <SFML/Graphics.hpp>
#include "anthill.hpp"
#include "enemy.hpp"
#include <ctime>
#include <iostream>
#include "map.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Ant Simulation");
    window.setFramerateLimit(60);
    sf::Clock food_and_sticks_Clock;

    //    if (enity.isAnt){
    //     Ant* ant = (Ant*) entity.ptr;
    //    }

    std::srand(0);

    
    Anthill anthill;
    positionMap[Position{400, 300}].hasAnthill = true;
    positionMap[Position{400, 300}].ptr = &anthill;
    for (int i = 0; i < 20; ++i)
    {
        float x = std::rand() % 800;
        float y = std::rand() % 600;
        anthill.addAnt(std::make_shared<Ant>(x, y));
        positionMap[Position{x, y}].hasAnt = true;
        positionMap[Position{x, y}].ptr = anthill.ants[i].get();
    }

    Enemy enemy(400.f, 300.f);

    while (window.isOpen())
    {

        // Обработка событий через новый API
        while (auto event = window.pollEvent())
        {
            // Проверка типа события через is()
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        if (food_and_sticks_Clock.getElapsedTime().asSeconds() >= 2.f)
        {
            // Добавь еду здесь (например, создать объект еды и добавить его в массив)
            for (int i = 0; i < 5; ++i)
            {
                float x = std::rand() % 800;
                float y = std::rand() % 600;
                while (positionMap[Position{x, y}].hasFood)
                {
                    x = std::rand() % 800;
                    y = std::rand() % 600;
                }
                anthill.generateFood(std::make_shared<Food>(x, y));
                positionMap[Position{x, y}].hasFood = true;
                positionMap[Position{x, y}].ptr = anthill.foods[i].get();
                // Food* food  =  anthill.foods[i].get();
                // food->registerCircularBoundary(food->getPosition(), 10, food);
            }
            for (int i = 0; i < 5; ++i)
            {
                float x = std::rand() % 800;
                float y = std::rand() % 600;
                while (positionMap[Position{x, y}].hasStick)
                {
                    x = std::rand() % 800;
                    y = std::rand() % 600;
                }
                anthill.generateStick(std::make_shared<Stick>(x, y));
                positionMap[Position{x, y}].hasStick = true;
                positionMap[Position{x, y}].ptr = anthill.sticks[i].get();
            }
            std::cout << "Добавлена еда на поле!\n";
            food_and_sticks_Clock.restart();
        }
// Здесь была Анастасия Шипова из КНТ-2
        anthill.update();
        anthill.alertSoldiers(enemy);
        window.clear(sf::Color(0x22, 0x8B, 0x22));
        anthill.draw(window);
        enemy.draw(window);
        window.display();
    }

    return 0;
}