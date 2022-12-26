
#include "entity.hpp"
#include "ak.hpp"
#include "AWP.hpp"
#include "M4.hpp"
#include "enemy.hpp"


#ifndef PLAYER
#define PLAYER

class Player : public Entity {
private:

    Gun* gun;
    sf::RectangleShape model;
    sf::Texture texture;

public:

    static const sf::Vector2f size;

    Player(sf::Vector2f pos);
    ~Player();

    Ammo* Fire(sf::Vector2f vector);
    bool EnemyInside(Enemy& enemy);
    void SetGun(Gun* new_gun);
    std::string GetGunName() const;

    void Draw(sf::RenderWindow* window) override;
    bool CheckCollisionX(Block& block, double time) override;
    bool CheckCollisionY(Block& block, double time) override;

};

#endif

