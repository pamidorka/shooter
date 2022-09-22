
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

    dir.x = (double)(mouse_pos.x - player_pos.x);
    dir.y = (double)(mouse_pos.y - player_pos.y);

    double length = sqrt(dir.x * dir.x + dir.y * dir.y);

    dir.x /= length;
    dir.y /= length;
       
    return dir;
}

void Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {

    //if (event.type == sf::Event::MouseButtonPressed) {
    //    if (event.key.code == sf::Mouse::Left) {
    //        //sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    //        ammo.push_back(Ammo(sf::Vector2f(0, 0), sf::Vector2f(0.3, 0.3), 1));
    //    }
    //}
    //switch (event.type) {
    //case sf::Event::KeyPressed:
    //    if (event.key.code == sf::Keyboard::A) {
    //        player.Move(sf::Vector2f(-5.0, 0), time);
    //    }
    //    if (event.key.code == sf::Keyboard::D) {
    //        player.Move(sf::Vector2f(5.0, 0), time);
    //    }
    //    break;
    //case sf::Event::MouseButtonPressed:
    //    if (event.key.code == sf::Mouse::Left) {
    //        //sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    //        ammo.push_back(Ammo(sf::Vector2f(0, 0), sf::Vector2f(0.3, 0.3), 1));
    //    }
    //    break;
    //default:
    //    break;
    //}
}

void Map::Draw(sf::RenderWindow* window) {
    for (std::size_t i = 0; i < blocks.size(); i++) {
        blocks[i].Draw(window);
    }
    for (std::size_t i = 0; i < ammo.size(); i++) {
        ammo[i].Draw(window);
    }
    player.Draw(window);
    // for (std::size_t i = 0; i < enemy.size(); i++) {
    //     enemy[i].Draw(window);
    // }
}

/*

1. переписываем пули на список
2. сделать проверку на коллизии 

*/

void Map::PermanentsEvents(sf::RenderWindow* window, double time) {
    for (std::size_t i = 0; i < ammo.size(); i++) {
        ammo[i].Move(sf::Vector2f(0, 0), time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.Move(sf::Vector2f(-0.4, 0), time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.Move(sf::Vector2f(0.4, 0), time);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouse = sf::Mouse::getPosition(*window);
        Ammo* tmp = player.Fire(GetVector(player.GetPos(), mouse));
        if (tmp) {
            ammo.push_back(*tmp);
            delete tmp;
        }
    }
    /* if (!player.GetOnGround()) {
         player.Move(sf::Vector2f(0, 9.8), time);
     }*/

}