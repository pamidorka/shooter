
#include "entity.hpp"
#include "ak.hpp"
 
class Player : public Entity {
private:

    Gun gun;
    sf::VertexArray model;

    void ResetModel();

public:

    static const sf::Vector2f size;

    Player(sf::Vector2f pos);
    ~Player();

    Ammo* Fire(sf::Vector2f vector);
    
    void Move(sf::Vector2f vector, double time) override;
    bool InsideMe(sf::Vector2f vertex) override;
    void Draw(sf::RenderWindow* window) override;

};

