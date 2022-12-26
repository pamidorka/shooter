
#include "entity.hpp"
#include "ammo.hpp"

#ifndef ENEMY
#define ENEMY

class Enemy : public Entity {
protected:

    int damage;
    sf::RectangleShape model;
    sf::Texture texture;

public:

    Enemy(const char* name);
    
    bool InEnemy(Ammo bullet);
    sf::RectangleShape GetModel();
    int GetDamage();

    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block& block, double time) override;
    bool CheckCollisionY(Block& block, double time) override;

};

#endif