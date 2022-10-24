
#include "entity.hpp"
#include "ak.hpp"
#include "enemy.hpp"


#ifndef PLAYER
#define PLAYER

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
    bool EnemyInside(Enemy& enemy);

    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block& block, double time) override;
    bool CheckCollisionY(Block& block, double time) override;

};

#endif

