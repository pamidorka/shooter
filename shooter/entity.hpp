
#include <SFML/Graphics.hpp>

#include "block.hpp"

#ifndef ENTITY
#define ENTITY

class Entity {
protected:
    
    char hp;
    bool on_ground;
    sf::Vector2f position;
    sf::Vector2f velocity;
    double gravity;

public:

    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual bool CheckCollisionX(Block& block, double time) = 0;
    virtual bool CheckCollisionY(Block& block, double time) = 0;

    void Move(double time);
    void Jump(float y);
    void SetVelosityX(float x);
    void SetVelosityY(float y);
    sf::Vector2f GetVelocity() const;
    bool GetOnGround() const;
    void SetOnGround(bool value);
    void ChangeHp(int delta_hp);
    sf::Vector2f GetPos() const;
    int GetHp() const;

};

#endif
