
#include "roles.hpp"
#include <iostream>

void Soldier::work() {
    std::cout << "Soldier is patrolling or fighting...\n";
}

void Gatherer::work() {
    std::cout << "Gatherer is collecting food...\n";
}

void Builder::work() {
    std::cout << "Builder is expanding the anthill...\n";
}

void Cleaner::work() {
    std::cout << "Cleaner is cleaning the anthill...\n";
}
