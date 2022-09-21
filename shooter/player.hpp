
#include "entity.hpp"
#include "machinegun.hpp"
 
class Player : public Entity {
private:

    Gun gun;
    void VertexReset() override;

public:

    static const sf::Vector2f size;

    Player(sf::Vector2<double> pos);
    ~Player();

    void Fire(sf::Vector2f vector, double time);
    
    void Move(sf::Vector2<double> vector, double time) override;
    bool InsideMe(sf::Vector2f vertex) override;
    void Draw(sf::RenderWindow* window) override;
    bool GetOnGround() override;


};

