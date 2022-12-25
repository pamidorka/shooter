
#include "enemy/red.hpp"
#include "enemy/yellow.hpp"
#include "enemy/green.hpp"

#ifndef FACTORY__
#define FACTORY__

class Factory {
private:

    float split_one;
    float split_two;

public:

    Factory(char difficulty);
    ~Factory();

    Enemy GiveMe(sf::Vector2f pos);

};

#endif