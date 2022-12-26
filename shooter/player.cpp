
#include "player.hpp"

#include <iostream>

const sf::Vector2f Player::size = sf::Vector2f(50, 50);

Player::Player(sf::Vector2f pos) {

    model = sf::RectangleShape(size);
    gun = new AK();

    position = pos;
    velocity.x = 0;
    velocity.y = 0;
    gravity = 0.002;
    hp = 10;
    
    texture.loadFromFile("player.png");
    model.setPosition(pos);

}

Player::~Player() {
    delete gun;
}

Ammo* Player::Fire(sf::Vector2f vector) {
    if (!gun->CanShoot()) {
        gun->Cooldown();
        return nullptr;
    }
    gun->Reset();
    return new Ammo(position + size / 2.f, vector, gun->GetDmg());
}

bool Player::EnemyInside(Enemy& enemy) {
    return enemy.GetModel().getGlobalBounds().intersects(model.getGlobalBounds());
}

void Player::SetGun(Gun* new_gun) {
    delete gun;
    gun = new_gun;
}

std::string Player::GetGunName() const {
    return gun->GetGunName();
}

void Player::SetPosition(sf::Vector2f pos) {
    position = pos;
}

void Player::Draw(sf::RenderWindow* window) {
    model.setPosition(position);
    model.setTexture(&texture);
    window->draw(model);
}

bool Player::CheckCollisionX(Block& block, double time) {
    Block tmp(sf::Vector2f(position.x + velocity.x * time, position.y), size);
    return block.Intersects(tmp);
}

bool Player::CheckCollisionY(Block& block, double time) {
    Block tmp(sf::Vector2f(position.x, position.y + velocity.y * time), size);
    return block.Intersects(tmp);
}
