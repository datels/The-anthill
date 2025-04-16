// #include <stdexcept>
#include "ant.hpp"
#include "food.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.hpp"

sf::Texture Ant::texture;
Ant::Ant(float x, float y)
    : velocity(0, 0),
      age(0),
      health(100),
      busy(false),
      sprite(texture)
{
    if (texture.getSize() == sf::Vector2u(0, 0))
    {

        if (!texture.loadFromFile("assets/ant.png"))
        {
            std::cerr << "Texture load failed\n";
            return;
        }
    }
    sprite.setTexture(texture);
    sf::Vector2f position(x, y);
    sprite.setPosition(position);
    sprite.setOrigin({texture.getSize().x / 2.f,
                      texture.getSize().y / 2.f});
}

sf::Vector2f normalize(sf::Vector2f v)
{
    float len = std::hypot(v.x, v.y);
    return len > 0 ? v / len : sf::Vector2f(0, 0);
}

void Ant::update()
{
    if (this->sprite.getPosition().x < 0 || this->sprite.getPosition().x > 800 || this->sprite.getPosition().y < 0 || this->sprite.getPosition().y > 600)
    {
        if (this->sprite.getPosition().x < 0)
        {
            this->sprite.setPosition(sf::Vector2f(800, this->sprite.getPosition().y));
        }
        if (this->sprite.getPosition().x > 800)
        {
            this->sprite.setPosition(sf::Vector2f(0, this->sprite.getPosition().y));
        }
        if (this->sprite.getPosition().y < 0)
        {
            this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x, 600));
        }
        if (this->sprite.getPosition().y > 600)
        {
            this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x, 0));
        }
    }
    float next_x = sprite.getPosition().x + velocity.x;
    float next_y = sprite.getPosition().y + velocity.y;
    if (positionMap[Position{sprite.getPosition().x, sprite.getPosition().y}].hasFood){
        Food* food = static_cast<Food*>(positionMap[Position{next_x, next_y}].ptr);       
        food->eat();
    }
    sprite.move(velocity);
    if (std::rand() % 1000 < 10)
    {
        velocity = normalize({(std::rand() % 3 - 1) * 1.0f, (std::rand() % 3 - 1) * 1.0f});
    }
    positionMap[Position{sprite.getPosition().x, sprite.getPosition().y}].hasAnt = true;
    positionMap[Position{sprite.getPosition().x, sprite.getPosition().y}].ptr = this;
    this->registerCircularBoundary(sprite.getPosition(), 50, this);
    // если наткнулся на еду
    // поел()
    // если палка
    // отнес палку
    // пошел в муравейник
}
void Ant::draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}
void Ant:: registerCircularBoundary(sf::Vector2f center, int radius, Ant* obj) {
    for (float angle = 0; angle < 2 * M_PI; angle += 0.1f) {
        float x = static_cast<int>(center.x + radius * std::cos(angle));
        float y = static_cast<int>(center.y + radius * std::sin(angle));
        //если в эту окружность попала еда 
        if (positionMap[Position{x,y}].hasFood){/*тогда еда должна быть съедена + соответствующие бафы хп все дела,
            эту еду удалить с карты и записать в эту ячейку в мапе указатель муравья*/}
        positionMap[Position{x,y}].ptr = obj;
        positionMap[Position{x,y}].hasAnt = true;
    }
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

void Ant::goTo(const sf::Vector2f &position)
{
    float x, x1, x2, y1, y2;
    x2 = position.x;      //=400
    y2 = position.y;      //=400
    x1 = getPosition().x; // 100
    y1 = getPosition().y; // 100
    float y = getPosition().y;
    if (y == position.y)
        return;
    if (y > position.y)
    {
        sprite.move(velocity);//яяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяяя

        y--;
        x = ((y - y1) / (y2 - y1)) * (x2 - x1) + x1;
        velocity = sf::Vector2f((x - x1) * 1.0f, (y - y1)   * 1.0f);
    }
    else
    {
        sprite.move(velocity);
        y++;
        x = ((y - y1) / (y2 - y1)) * (x2 - x1) + x1;
        velocity = sf::Vector2f((x - x1) * 1.0f, (y - y1) * 1.0f);
    }
    positionMap[Position{sprite.getPosition().x, sprite.getPosition().y}].hasAnt = true;
    positionMap[Position{sprite.getPosition().x, sprite.getPosition().y}].ptr = this;
}

void Ant::subscribeToNotifier(Notifier &notifier)
{       
    if (!busy)
    {
        std::shared_ptr<Ant> self = shared_from_this();
        notifier.subscribe([self]()
                           { self->onAlert(); });
        busy = true;
    }
}
