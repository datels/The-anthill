#ifndef ANT_HPP
#define ANT_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "roles.hpp"
#include "notifier.hpp"

class Ant : public std::enable_shared_from_this<Ant>{
public:
    Ant(float x, float y);
    void update();
    void draw(sf::RenderWindow& window) const;
    void growOlder();
    int getAge() const;
    std::string getRoleName() const;
    sf::Vector2f getPosition() const;
    bool isNear(const sf::Vector2f& other, float distance) const;
    void onAlert();
    void subscribeToNotifier(Notifier& notifier);

private:
    
    
    sf::Vector2f velocity;

    static sf::Texture texture;
    sf::Sprite sprite;

    int age;
    float health;
    std::shared_ptr<Role> role;
    void updateRole();
    bool subscribed;
};

#endif