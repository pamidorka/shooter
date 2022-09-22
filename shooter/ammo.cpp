
#include "ammo.hpp"

Ammo::Ammo(sf::Vector2f pos, sf::Vector2f velocity, int dmg) {
    this->velocity = velocity;
    damage = dmg;

    position = pos;

    model = sf::CircleShape(5.0);
    model.setPosition(pos);
    model.setFillColor(sf::Color::Magenta);

}

Ammo::~Ammo() {

}

void Ammo::Move(sf::Vector2f vector, double time) {
    position.x += velocity.x * time;
    position.y += velocity.y * time;
}

bool Ammo::InsideMe(sf::Vector2f vertex) {
    return false;
}

void Ammo::Draw(sf::RenderWindow* window) {
    model.setPosition(position);
    window->draw(model);
}

