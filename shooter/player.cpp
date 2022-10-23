
#include "player.hpp"

#include <iostream>

const sf::Vector2f Player::size = sf::Vector2f(50, 50);

Player::Player(sf::Vector2f pos) {

    model = sf::VertexArray(sf::PrimitiveType::Quads, 4);
    gun = AK();

    position = pos;
    velocity.x = 0;
    velocity.y = 0;
    gravity = 0.002;
    hp = 50;

    ResetModel();

    for (unsigned int i = 0; i < 4; i++) {
        model[i].color = sf::Color::Blue;
    }
}

Player::~Player() {

}

void Player::ResetModel() {
    model[0].position.x = position.x - size.x / 2.0;
    model[0].position.y = position.y - size.y / 2.0;

    model[1].position.x = position.x + size.x / 2.0;
    model[1].position.y = position.y - size.y / 2.0;

    model[2].position.x = position.x + size.x / 2.0;
    model[2].position.y = position.y + size.y / 2.0;

    model[3].position.x = position.x - size.x / 2.0;
    model[3].position.y = position.y + size.y / 2.0;
}


Ammo* Player::Fire(sf::Vector2f vector) {
    if (!gun.CanShoot()) {
        gun.Cooldown();
        return nullptr;
    }
    gun.Reset();
    return new Ammo(position, vector, gun.GetDmg());
}

bool Player::EnemyInside(Enemy& enemy) {
    return enemy.GetModel().getGlobalBounds().intersects(model.getBounds());
}

void Player::Draw(sf::RenderWindow* window) {
    ResetModel();
    window->draw(model);
}

bool Player::CheckCollisionX(Block block, double time) {
    sf::FloatRect tmp = model.getBounds();
    tmp.left += velocity.x * time;
    tmp.top -= 0.1;
    
    return block.GetBody().getBounds().intersects(tmp);
}

bool Player::CheckCollisionY(Block block, double time) {
    sf::FloatRect tmp = model.getBounds();
    tmp.top += velocity.y * time;
    return block.GetBody().getBounds().intersects(tmp);
}
