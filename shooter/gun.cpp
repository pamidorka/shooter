
#include "gun.hpp"

Gun::Gun() {

}

Gun::~Gun() {

}

void Gun::Fire(sf::Vector2f bh_vector, double time) {
    ammo.push_back(Ammo(bh_vector, damage));
}

void Gun::Draw(sf::RenderWindow* window) {
    window->draw(model);
    for (std::size_t i = 0; i < ammo.size(); i++) {
        ammo[i].Draw(window);
    }
}