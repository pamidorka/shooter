
#include <SFML/Graphics.hpp>

#ifndef GUN
#define GUN

class Gun {
protected:

    int damage;
    sf::VertexArray model;

public:

    Gun();
    ~Gun();

    void Fire(sf::Vector2f bh_vector, double time);
    void Draw(sf::RenderWindow* window);

};

#endif