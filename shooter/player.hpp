
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
    
    void Left();
    void Right();

    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block block, double time) override;
    bool CheckCollisionY(Block block, double time) override;

};

