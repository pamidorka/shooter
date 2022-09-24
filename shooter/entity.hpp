
#include <SFML/Graphics.hpp>

#include "block.hpp"

#ifndef ENTITY
#define ENTITY

class Entity {
protected:
    
    int hp;
    bool on_ground;
    sf::Vector2f position;
    sf::Vector2f velocity;

public:

    virtual void Move(double time) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual bool CheckCollision(Block block, double time) = 0;

    void ResetVelosityX();
    bool GetOnGround();
    void ChangeHp(int delta_hp);
    sf::Vector2f GetPos();

};

#endif
