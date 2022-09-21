
#include "ammo.hpp"

Ammo::Ammo(sf::Vector2f vector, int dmg) {
    fly_vector = vector;
    damage = dmg;

    model = sf::CircleShape(3);
    model.setFillColor(sf::Color::Magenta);

}

Ammo::~Ammo() {

}

void Ammo::Move(double time) {
    model.setPosition(sf::Vector2f(model.getPosition().x + fly_vector.x * time, model.getPosition().y + fly_vector.y * time));
}

void Ammo::Draw(sf::RenderWindow* window) {
    window->draw(model);
}