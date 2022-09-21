
#include <SFML/Graphics.hpp>

#ifndef ENTITY
#define ENTITY

class Entity {
protected:
    
    int hp;
    bool on_ground;
    sf::Vector2f position;
    sf::VertexArray model;

    virtual void VertexReset() = 0;

public:

    virtual void Move(sf::Vector2f vector, double time) = 0;
    virtual bool InsideMe(sf::Vector2f vertex) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual bool GetOnGround() = 0;

    void ChangeHp(int delta_hp);

};

#endif
