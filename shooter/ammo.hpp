
#include <SFML/Graphics.hpp>

#include "entity.hpp"

#ifndef AMMO
#define AMMO

class Ammo : public Entity {
private:

    sf::CircleShape model;
    int damage;
    sf::Texture texture;

public:

    Ammo() = delete;
    Ammo(sf::Vector2f pos, sf::Vector2f velocity, int dmg);
    ~Ammo();

    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block& block, double time) override;
    bool CheckCollisionY(Block& block, double time) override;

    sf::CircleShape GetModel();
    int GetDamage();

};

#endif