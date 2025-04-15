//#include <stdexcept>
#include "ant.hpp"
#include <cmath>
#include <iostream>
sf::Texture Ant::texture;
Ant::Ant(float x, float y) 
    : velocity(0, 0), 
      age(0), 
      health(100), 
      subscribed(false),
      sprite(texture) 
{
    if (texture.getSize() == sf::Vector2u(0, 0)) {
        
        if (!texture.loadFromFile("assets/me.png")) {
            std::cerr << "Texture load failed\n";
            return;
        }
    }
    sprite.setTexture(texture);
    sf::Vector2f position(x, y);
    sprite.setPosition(position);
    sprite.setOrigin({
        texture.getSize().x / 2.f,
        texture.getSize().y / 2.f
    });
}
    
    
    


void Ant::update()
{
    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x > 800 || this->sprite.getPosition().y < 0 || this->sprite.getPosition().y > 600) {
        if (this->sprite.getPosition().x < 0) {
            this->sprite.setPosition(sf::Vector2f(800,this->sprite.getPosition().y) );
        }
        if (this->sprite.getPosition().x > 800) {
            this->sprite.setPosition(sf::Vector2f(0,this->sprite.getPosition().y) );
        }
        if (this->sprite.getPosition().y < 0) {
            this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x,600) );
        }
        if (this->sprite.getPosition().y > 600) {
            this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x,0) );
        }

    }
    sprite.move(velocity);
    if (std::rand() % 100 < 10) {
        velocity = sf::Vector2f((std::rand() % 3 - 1) * 1.0f, (std::rand() % 3 - 1) * 1.0f);
    }
}

void Ant::draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

///
void Ant::growOlder()
{
    age++;
    updateRole();
}

int Ant::getAge() const
{
    return age;
}

std::string Ant::getRoleName() const
{
    return role ? role->name() : "None";
}

void Ant::updateRole()
{
    if (age == 20)
        role = std::make_shared<Nanny>();
    else if (age == 40)
        role = std::make_shared<Soldier>();
    else if (age == 60)
        role = std::make_shared<Gatherer>();
    else if (age == 80)
        role = std::make_shared<Builder>();
    else if (age == 100)
        role = std::make_shared<Cleaner>();
}

sf::Vector2f Ant::getPosition() const
{
    return sprite.getPosition();
}

bool Ant::isNear(const sf::Vector2f &other, float distance) const
{
    sf::Vector2f pos = sprite.getPosition();
    return std::hypot(pos.x - other.x, pos.y - other.y) < distance;
}

void Ant::onAlert()
{
    if (getRoleName() == "Soldier")
    {
        std::cout << "Soldier ant responding to threat!\n";
    }
}

void Ant::subscribeToNotifier(Notifier &notifier)
{
    if (!subscribed)
    {
        std::shared_ptr<Ant> self = shared_from_this();
        notifier.subscribe([self]()
                           { self->onAlert(); });
        subscribed = true;
    }
}
