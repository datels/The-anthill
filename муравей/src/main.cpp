#include <SFML/Graphics.hpp>
#include "anthill.hpp"
#include "enemy.hpp"
#include <ctime>
#include <iostream>

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