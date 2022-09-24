
#include "entity.hpp"

void Entity::ChangeHp(int delta_hp) {
    hp += delta_hp;
}

void Entity::ResetVelosityX() {
    velocity.x = 0;
}

bool Entity::GetOnGround() {
    return on_ground;
}

sf::Vector2f Entity::GetPos() {
    return position;
}