
#include <fstream>
#include <iostream>

#include "map.hpp"

Map::Map(const char* from, sf::Vector2u size) {
    screen = size;
    blocks.clear();
    blocks.push_back(Block(sf::Vector2f(-50, 0), sf::Vector2f(50, screen.y)));
    blocks.push_back(Block(sf::Vector2f(0, screen.y), sf::Vector2f(screen.x, 50)));
    blocks.push_back(Block(sf::Vector2f(screen.x, 0), sf::Vector2f(50, screen.y)));
    blocks.push_back(Block(sf::Vector2f(0, -50), sf::Vector2f(screen.x, 50)));
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

    enemy.push_back(RedEnemy(sf::Vector2f(700, 50)));
    enemy.push_back(RedEnemy(sf::Vector2f(600, 50)));
    enemy.push_back(RedEnemy(sf::Vector2f(500, 50)));

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

void Map::MoveCollision(Entity &entity, double time) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        if (entity.CheckCollisionX(*i, time)) {
            entity.ResetVelosityX();
            return;
        }
    }
}

void Map::FallCollision(Entity &entity, double time) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        if (entity.CheckCollisionY(*i, time)) {
            if (entity.GetVelocity().y > 0) {
                entity.SetOnGround(true);
            }
            entity.SetVelosityY(0);
            return;
        }
    }
    entity.SetOnGround(false);
}

void Map::EnemyHandlerAI(double time) {

}

void Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {

}

void Map::Draw(sf::RenderWindow* window) {
    for (auto i = ammo.begin(); i != ammo.end(); i++) {
        i->Draw(window);
    }
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        i->Draw(window);
    }
    player.Draw(window);
    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        i->Draw(window);
    }
}

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

    for (auto j = ammo.begin(); j != ammo.end();) {
        if (enemy.size() <= 0) break;
        bool enemy_hit = false;
        for (auto i = enemy.begin(); i != enemy.end(); i++) {
            if (i->InEnemy(*j)) {
                i->ChangeHp(-(j->GetDamage()));
                if (i->GetHp() <= 0) {
                    enemy.erase(i);
                }
                enemy_hit = true;
                break;
            }
        }
        if (enemy_hit) {
            j = ammo.erase(j);
        }
        else {
            j++;
        }
    }
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.Left();
        MoveCollision(player, time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.Right();
        MoveCollision(player, time);
    }
    else {
        player.ResetVelosityX();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.GetOnGround()) {
        player.SetVelosityY(-0.8);
        player.SetOnGround(false);
    }
    
    FallCollision(player, time);

    player.Move(time);

    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        FallCollision(*i, time);
    }

    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        i->Move(time);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouse = sf::Mouse::getPosition(*window);
        Ammo* tmp = player.Fire(GetVector(player.GetPos(), mouse));
        if (tmp) {
            ammo.push_back(*tmp);
            delete tmp;
        }
    }
}