
#include "entity.hpp"

void Entity::ChangeHp(int delta_hp) {
    hp += delta_hp;
}

void Entity::SetVelosityX(float x) {
    velocity.x = x;
}

void Entity::SetVelosityY(float y) {
    velocity.y = y;
}

sf::Vector2f Entity::GetVelocity() const {
    return velocity;
}

bool Entity::GetOnGround() const {
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

void Entity::Jump(float y) {
    if (on_ground) {
        velocity.y = y;
        on_ground = false;
    }
}

sf::Vector2f Entity::GetPos() const {
    return position;
}

int Entity::GetHp() const {
    return hp;
}
