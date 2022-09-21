
#include "enemy/red.hpp"
#include "enemy/yellow.hpp"
#include "enemy/green.hpp"

class Factory {
private:

    char difficulty;

public:

    Factory(char difficulty);
    ~Factory();

    Enemy GiveMe();

};