
#include "player.hpp"

#include <iostream>

const sf::Vector2f Player::size = sf::Vector2f(25, 100);

Player::Player(sf::Vector2<double> pos) {

    model = sf::VertexArray(sf::PrimitiveType::Quads, 4);
    gun = MachineGun();

    position = pos;

    model[0].position.x = pos.x;
    model[0].position.y = pos.y;

    model[1].position.x = pos.x + size.x;
    model[1].position.y = pos.y;

    model[2].position.x = pos.x + size.x;
    model[2].position.y = pos.y + size.y;

    model[3].position.x = pos.x;
    model[3].position.y = pos.y + size.y;

    for (unsigned int i = 0; i < 4; i++) {
        model[i].color = sf::Color::Blue;
    }
}

Player::~Player() {

}

void Player::Fire(sf::Vector2f vector, double time) {
    gun.Fire(vector, time);
}

void Player::Move(sf::Vector2<double> vector, double time) {
    for (unsigned int i = 0; i < 4; i++) {
        model[i].position.x += vector.x * time;
        model[i].position.y += vector.y * time;
    }
}

void Player::Draw(sf::RenderWindow* window) {
    window->draw(model);
}

bool Player::InsideMe(sf::Vector2f vertex) {
    if ((position.x + size.x >= vertex.x) && (position.y + size.y >= vertex.y) && (vertex.x >= position.x) && (vertex.y >= position.y)) {
        return true;
    }
    return false;
}