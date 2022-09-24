
#include <fstream>
#include <iostream>

#include "map.hpp"

Map::Map(const char* from, sf::Vector2u size) {
    screen = size;
    blocks.clear();
    std::fstream file(from, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "file not found" << std::endl;
        return;
    }
    std::size_t count = 0;
    file.read((char*)&count, sizeof(std::size_t));
    for (std::size_t i = 0; i < count; i++) {
        Block tmp(sf::Vector2f(0, 0), sf::Vector2f(50, 50), sf::Color::Black);
        tmp.LoadFrom(file);
        blocks.push_back(tmp);
    }
    file.close();
}

Map::Map(sf::Vector2u size) {
    screen = size;

    blocks.push_back(Block(sf::Vector2f(size.x / 2, size.y / 2), sf::Vector2f(50, 50)));
    blocks.push_back(Block(sf::Vector2f(size.x / 2 - 150, size.y / 2), sf::Vector2f(50, 50)));
    blocks.push_back(Block(sf::Vector2f(500, 100), sf::Vector2f(50, 50)));

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

void Map::PlayerMoveCollision(double time) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        if (player.CheckCollision(*i, time)) {
            return;
        }
    }
    player.Move(time);
}

void Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {

    //if (event.type == sf::Event::MouseButtonPressed) {
    //    if (event.key.code == sf::Mouse::Left) {
    //        //sf::Vector2i mouse = sf::Mouse::getPosition(*window);
    //        ammo.push_back(Ammo(sf::Vector2f(0, 0), sf::Vector2f(0.3, 0.3), 1));
    //    }
    //}
    /*switch (event.type) {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::A) {
            player.Left();
        }
        else if (event.key.code == sf::Keyboard::D) {
            player.Right();
        }
        break;
    default:
        break;
    }*/
}

void Map::Draw(sf::RenderWindow* window) {
    for (auto i = ammo.begin(); i != ammo.end(); i++) {
        i->Draw(window);
    }
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        i->Draw(window);
    }
    player.Draw(window);
    // for (std::size_t i = 0; i < enemy.size(); i++) {
    //     enemy[i].Draw(window);
    // }
}

/*

1. переписываем пули на список | ready
2. сделать проверку на коллизии 
2.1 гравитация

*/

void Map::PermanentsEvents(sf::RenderWindow* window, double time) {
    for (auto i = ammo.begin(); i != ammo.end(); i++) {
        i->Move(time);
    }

    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        for (auto j = ammo.begin(); j != ammo.end();) {
            if (i->InBlock(j->GetPos())) {
                j = ammo.erase(j);
            }
            else {
                j++;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.Left();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.Right();
    }
    else {
        player.ResetVelosityX();
    }
    PlayerMoveCollision(time);
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