
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
    double gravity;

public:

    virtual void Move(double time) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual bool CheckCollisionX(Block block, double time) = 0;
    virtual bool CheckCollisionY(Block block, double time) = 0;

    void ResetVelosityX();
    void SetVelosityY(float y);
    sf::Vector2f GetVelocity();
    bool GetOnGround();
    void SetOnGround(bool value);
    void ChangeHp(int delta_hp);
    sf::Vector2f GetPos();

};

#endif
