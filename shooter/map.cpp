
#include <fstream>

#include "map.hpp"

Map::Map(const char* from, sf::Vector2u size) {

}

Map::Map(sf::Vector2u size) {
    screen = size;
}

Map::~Map() {

}

void Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::A) {
            player.Move(sf::Vector2f(-30, 0), time);
        }
        if (event.key.code == sf::Keyboard::D) {
            player.Move(sf::Vector2f(30, 0), time);
        }
        break;
    default:
        break;
    }
}

void Map::Draw(sf::RenderWindow* window) {
    for(std::size_t i = 0; i < blocks.size(); i++) {
        blocks[i].Draw(window);
    }
    player.Draw(window);
    // for (std::size_t i = 0; i < enemy.size(); i++) {
    //     enemy[i].Draw(window);
    // }
}

void Map::CollisionListener(double time) {
    // if (!player.GetOnGround()) {
    //     player.Move(sf::Vector2f(0, 9.8), time);
    // }

}