#ifndef roles_hpp
#define roles_hpp

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Enemy;

class Role
{
public:
    virtual ~Role() = default;
    virtual std::string name() const = 0;
    virtual void work() = 0;
};

class Enemy 
{
public:
    void die() {
        bool isAlive = false;
    }

    bool isAlive() const { return isAlive; }

private:
    bool isAlive = true;
};
class Soldier : public Role 
{
private:
    int attackPower = 100; 

public:
    std::string name() const override { return "Soldier"; }


    void attackEnemy(Enemy& enemy)
    {
        enemy.die();
    }

};

class Builder : public Role 
{
private:
    enum class StickSize { Small, Big };

public:
    std::string name() const override { return "Builder"; }


private:
    struct Stick 
    {
        StickSize size;
        int hp;//колво хп для муравейника
    };

    void handleStick(Stick& stick)
    {
        if (stick.size == StickSize::Small) 
        {
            carrySmallStick(stick);
        }
        else 
        {
            callForHelp(stick);
        }
    }

    void carrySmallStick(Stick& stick) 
    {
        // Логика переноса маленькой палки
    }

    void callForHelp(Stick& stick) 
    {
        // Логика вызова помощи
        splitAndCarryStick(stick);
    }

    void splitAndCarryStick(Stick& stick) 
    {
        // Логика переноса
    }

};

class Gatherer : public Role 
{
private:
    enum class FoodSize { Small, Big };

public:
    std::string name() const override { return "Gatherer"; }

    void work() override 
    {
            searchForFood();
    }

private:
    struct Food 
    {
        FoodSize size;
        int nutrition; //скок хп лутает муравей
    };

    void handleFood(Food& food) 
    {
        if (food.size == FoodSize::Small) 
        {
            eatAlone(food);
        }
        else 
        {
            callFriendsToEat(food);
        }
    }

    void eatAlone(Food& food) 
    {
        increaseHealth(food.nutrition);
    }

    void callFriendsToEat(Food& food) {
        shareFood(food);
    }

    void shareFood(Food& food) 
    {
        int nutritionPerAnt = food.nutrition / 3;
        increaseHealth(nutritionPerAnt);
        // как достать индексы других муравьев хз
    }

    void increaseHealth(int nutrition)
    {
        ant.health += nutrition;
    }

    
};
#endif
