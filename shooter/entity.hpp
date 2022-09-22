
#include <SFML/Graphics.hpp>

#ifndef ENTITY
#define ENTITY

class Entity {
protected:
    
    int hp;
    bool on_ground;
    sf::Vector2f position;

public:

    virtual void Move(sf::Vector2f vector, double time) = 0;
    virtual bool InsideMe(sf::Vector2f vertex) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;

    bool GetOnGround();
    void ChangeHp(int delta_hp);
    sf::Vector2f GetPos();

};

#endif
