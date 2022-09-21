
#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Ammo {
private:

    sf::Vector2f velocity;
    int damage;

public:

    Ammo() = delete;
    Ammo(sf::Vector2<double> pos, sf::Vector2f velocity, int dmg);
    ~Ammo();

    void Move(sf::Vector2<double> vector, double time);
    bool InsideMe(sf::Vector2f vertex);
    void Draw(sf::RenderWindow* window);

};