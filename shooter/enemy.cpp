
#include "enemy.hpp"

Enemy::Enemy(const char* name) {
    texture.loadFromFile(name);
}

bool Enemy::InEnemy(Ammo bullet) {
    return model.getGlobalBounds().intersects(bullet.GetModel().getGlobalBounds());
}

sf::RectangleShape Enemy::GetModel() {
    return model;
}

int Enemy::GetDamage() {
    return damage;
}

void Enemy::Draw(sf::RenderWindow* window) {
    model.setPosition(position);
    model.setTexture(&texture);
	window->draw(model);
}

bool Enemy::CheckCollisionX(Block& block, double time) {
    sf::FloatRect tmp = model.getGlobalBounds();
    tmp.left += velocity.x * time;
    tmp.top -= 0.1;
    return block.GetBody().getBounds().intersects(tmp);
}

bool Enemy::CheckCollisionY(Block& block, double time) {
    sf::FloatRect tmp = model.getGlobalBounds();
    tmp.top += velocity.y * time;
    return block.GetBody().getBounds().intersects(tmp);
}