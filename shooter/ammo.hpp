
#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Ammo : public Entity {
private:

    sf::Vector2f velocity;
    sf::CircleShape model;
    int damage;

public:

    Ammo() = delete;
    Ammo(sf::Vector2f pos, sf::Vector2f velocity, int dmg);
    ~Ammo();

    void Move(sf::Vector2f vector, double time) override;
    bool InsideMe(sf::Vector2f vertex) override;
    void Draw(sf::RenderWindow* window) override;

};