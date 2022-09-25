
#include <SFML/Graphics.hpp>

#include "entity.hpp"

#ifndef AMMO
#define AMMO

class Ammo : public Entity {
private:

    sf::CircleShape model;
    int damage;

public:

    Ammo() = delete;
    Ammo(sf::Vector2f pos, sf::Vector2f velocity, int dmg);
    ~Ammo();

    void Move(double time) override;
    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block block, double time) override;
    bool CheckCollisionY(Block block, double time) override;

};

#endif