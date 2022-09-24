
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

void Ammo::Move(double time) {
    position.x += velocity.x * time;
    position.y += velocity.y * time;
}

void Ammo::Draw(sf::RenderWindow* window) {
    model.setPosition(position);
    window->draw(model);
}

bool Ammo::CheckCollision(Block block, double time) {
    return false;
}

