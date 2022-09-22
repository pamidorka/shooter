
#include <fstream>
#include <iostream>

#include "map.hpp"

Map::Map(const char* from, sf::Vector2u size) {

}

Map::Map(sf::Vector2u size) {
    screen = size;
}

Map::~Map() {

}

sf::Vector2f Map::GetVector(sf::Vector2f player_pos, sf::Vector2i mouse_pos) {
    sf::Vector2f dir;

    return dir;
}

void Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::A) {
            player.Move(sf::Vector2f(-5.0, 0), time);
        }
        if (event.key.code == sf::Keyboard::D) {
            player.Move(sf::Vector2f(5.0, 0), time);
        }
        break;
    case sf::Event::MouseButtonPressed:
        if (event.key.code == sf::Mouse::Left) {
            //sf::Vector2i mouse = sf::Mouse::getPosition(*window);
            ammo.push_back(Ammo(sf::Vector2f(0, 0), sf::Vector2f(0.3, 0.3), 1));
        }
        break;
    default:
        break;
    }
}

void Map::Draw(sf::RenderWindow* window) {
    for (std::size_t i = 0; i < blocks.size(); i++) {
        blocks[i].Draw(window);
    }
    player.Draw(window);
    for (std::size_t i = 0; i < ammo.size(); i++) {
        ammo[i].Draw(window);
    }
    // for (std::size_t i = 0; i < enemy.size(); i++) {
    //     enemy[i].Draw(window);
    // }
}

void Map::CollisionListener(double time) {
    for (std::size_t i = 0; i < ammo.size(); i++) {
        ammo[i].Move(sf::Vector2f(0, 0), time);
    }
    // if (!player.GetOnGround()) {
    //     player.Move(sf::Vector2f(0, 9.8), time);
    // }

}