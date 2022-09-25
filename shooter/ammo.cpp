
#include "ammo.hpp"

Ammo::Ammo(sf::Vector2f pos, sf::Vector2f velocity, int dmg) {
    this->velocity = velocity;
    damage = dmg;
    on_ground = false;
    gravity = 0.0004;

    position = pos;

    model = sf::CircleShape(5.0);
    model.setPosition(pos);
    model.setFillColor(sf::Color(70, 40, 31));

}

Ammo::~Ammo() {

}

void Ammo::Draw(sf::RenderWindow* window) {
    model.setPosition(position);
    window->draw(model);
}

bool Ammo::CheckCollisionX(Block block, double time) {
    return false;
}

bool Ammo::CheckCollisionY(Block block, double time) {
    return false;
}

sf::CircleShape Ammo::GetModel() {
    return model;
}

int Ammo::GetDamage() {
    return damage;
}

