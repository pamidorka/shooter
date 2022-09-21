
#include <SFML/Graphics.hpp>

class Ammo {
private:

    sf::Vector2f fly_vector;
    sf::CircleShape model;
    int damage;

    void ResetModel();

public:

    Ammo() = delete;
    Ammo(sf::Vector2f vector, int dmg);
    ~Ammo();

    void Move(double time);
    void Draw(sf::RenderWindow* window);

};