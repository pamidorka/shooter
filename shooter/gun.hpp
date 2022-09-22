
#include <SFML/Graphics.hpp>
#include "ammo.hpp"

#ifndef GUN
#define GUN

class Gun {
protected:

    int damage;
    double delay;
    bool can_shoot = true;
    sf::Clock clock;

public:

    Gun() = default;
    virtual ~Gun();

    int GetDmg();
    void Cooldown();
    bool CanShoot();
    void Reset();

};

#endif