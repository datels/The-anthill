#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP

#include <vector>
#include <functional>

class Notifier {
public:
    void subscribe(std::function<void()> callback);
    void notifyAll();
private:
    std::vector<std::function<void()>> subscribers;
};

#endif