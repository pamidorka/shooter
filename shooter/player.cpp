
#include "player.hpp"

#include <iostream>

const sf::Vector2f Player::size = sf::Vector2f(25, 100);

Player::Player(sf::Vector2f pos) {

    model = sf::VertexArray(sf::PrimitiveType::Quads, 4);
    gun = AK();

    position = pos;

    ResetModel();

    for (unsigned int i = 0; i < 4; i++) {
        model[i].color = sf::Color::Blue;
    }
}

Player::~Player() {

}

void Player::ResetModel() {
    model[0].position.x = position.x - size.x / 2;
    model[0].position.y = position.y - size.y / 2;

    model[1].position.x = position.x + size.x / 2;
    model[1].position.y = position.y - size.y / 2;

    model[2].position.x = position.x + size.x / 2;
    model[2].position.y = position.y + size.y / 2;

    model[3].position.x = position.x - size.x / 2;
    model[3].position.y = position.y + size.y / 2;
}


Ammo* Player::Fire(sf::Vector2f vector) {
    if (!gun.CanShoot()) {
        gun.Cooldown();
        return nullptr;
    }
    gun.Reset();
    return new Ammo(position, vector, gun.GetDmg());
}

void Player::Move(sf::Vector2f vector, double time) {
    position.x += vector.x * time;
    position.y += vector.y * time;
}

void Player::Draw(sf::RenderWindow* window) {
    ResetModel();
    window->draw(model);
}

bool Player::InsideMe(sf::Vector2f vertex) {
    if ((position.x + size.x >= vertex.x) && (position.y + size.y >= vertex.y) && (vertex.x >= position.x) && (vertex.y >= position.y)) {
        return true;
    }
    return false;
}