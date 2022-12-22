
#include "enemy/red.hpp"
#include "enemy/yellow.hpp"
#include "enemy/green.hpp"

#ifndef FACTORY__
#define FACTORY__

class Factory {
private:

    char difficulty;

public:

    Factory(char difficulty);
    ~Factory();

    Enemy GiveMe();

};

#endif