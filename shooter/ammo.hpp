
#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Ammo : public Entity {
private:

    sf::Vector2f fly_vector;
    int damage;

public:

    Ammo() = delete;
    Ammo(sf::Vector2f vector, int dmg);
    ~Ammo();

    void Move(sf::Vector2<double> vector, double time) override;
    bool InsideMe(sf::Vector2f vertex) override;
    void Draw(sf::RenderWindow* window) override;

};