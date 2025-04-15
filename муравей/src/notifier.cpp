#include "notifier.hpp"

void Notifier::subscribe(std::function<void()> callback) {
    subscribers.push_back(callback);
}

void Notifier::notifyAll() {
    for (auto& sub : subscribers) sub();
}


