#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib> // для std::rand() и std::srand()
#include <ctime>   // для std::time()
#include <algorithm> // для std::shuffle
#include <random>    // для std::default_random_engine
#include "roles.hpp"
#include "ant.hpp"
#include "notifier.h"

void Notifier::subscribe(Builder* builder) {
    builders.push_back(builder);
}

void Notifier::subscribe(Ant* ant) {
    antSubscribers.push_back(ant);
}

void Notifier::sendAntsToStick(std::vector<Builder*>& builders, const sf::Vector2f& targetPosition) {
    std::vector<Builder*> availableBuilders;
    for (auto* builder : builders) {
        if builder.isBusy == false {
            availableBuilders.push_back(builder);
        }
    }
    std::shuffle(availableBuilders.begin(), availableBuilders.end(), std::default_random_engine(std::rand()));
    for (size_t i = 0; i < std::min(size_t(2), availableBuilders.size()); ++i) {
        availableBuilders[i]->goTo(targetPosition);
        availableBuilders[i]->setBusy(true);
    }
}


void Notifier::sendAntsToEat(std::vector<Ant*>& ants, const sf::Vector2f& targetPosition) {
    std::vector<Ant*> availableAnts;
    for (auto* ant : ants) {
        if builder.isBusy == false {
            availableBuilders.push_back(builder);
        }
    }
    std::shuffle(availableAnts.begin(), availableAnts.end(), std::default_random_engine(std::rand()));
    for (size_t i = 0; i < std::min(size_t(2), availableAnts.size()); ++i) {
        availableAnts[i]->goTo(targetPosition);
        availableAnts[i]->setBusy(true);
    }
}
