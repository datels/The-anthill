#ifndef ROLES_HPP
#define ROLES_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Role {
public:
    virtual ~Role() = default;
    virtual std::string name() const = 0;
    virtual void work() = 0;
};

class Soldier : public Role {
public:
    std::string name() const override { return "Soldier"; }
    void work() override;
};

class Gatherer : public Role {
public:
    std::string name() const override { return "Gatherer"; }
    void work() override;
};

class Builder : public Role {
public:
    std::string name() const override { return "Builder"; }
    void work() override;
};


#endif
