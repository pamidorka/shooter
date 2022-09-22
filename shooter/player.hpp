
#include "entity.hpp"
#include "machinegun.hpp"
 
class Player : public Entity {
private:

    Gun gun;
    sf::VertexArray model;

public:

    static const sf::Vector2f size;

    Player(sf::Vector2f pos);
    ~Player();

    void Fire(sf::Vector2f vector, double time);
    
    void Move(sf::Vector2f vector, double time) override;
    bool InsideMe(sf::Vector2f vertex) override;
    void Draw(sf::RenderWindow* window) override;

};

