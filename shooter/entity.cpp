
#include "entity.hpp"

void Entity::ChangeHp(int delta_hp) {
    hp += delta_hp;
}

void Entity::ResetVelosityX() {
    velocity.x = 0;
}

void Entity::SetVelosityY(float y) {
    velocity.y = y;
}

sf::Vector2f Entity::GetVelocity() {
    return velocity;
}

bool Entity::GetOnGround() {
    return on_ground;
}

void Entity::SetOnGround(bool value) {
    on_ground = value;
}

void Entity::Move(double time) {
    position.x += velocity.x * time;
    if (!on_ground) { velocity.y += gravity * time; }
    position.y += velocity.y * time;
}

sf::Vector2f Entity::GetPos() {
    return position;
}

int Entity::GetHp() {
    return hp;
}
