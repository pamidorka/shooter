
#include "ammo.hpp"

Ammo::Ammo(sf::Vector2f vector, int dmg) {
    fly_vector = vector;
    damage = dmg;

    

}

Ammo::~Ammo() {

}

void Ammo::Move(sf::Vector2<double> vector, double time) {
    for (unsigned int i = 0; i < 3; i++) {

    }
}

bool Ammo::InsideMe(sf::Vector2f vertex) {
    return false;
}

void Ammo::Draw(sf::RenderWindow* window) {
    window->draw(model);
}