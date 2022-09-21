
#include "ammo.hpp"

Ammo::Ammo(sf::Vector2<double> pos, sf::Vector2f velocity, int dmg) {
    this->velocity = velocity;
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
  
}