
#include <fstream>
#include <iostream>
#include <iomanip>

#include "map.hpp"
#include "MainMenu.hpp"

Map::Map(const char* from, sf::Vector2u size, sf::Font* load_font, char difficulty) : factory(difficulty), hud(sf::Vector2f(10, 0), load_font) {
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

    font = load_font;

    //enemy.push_back(RedEnemy(sf::Vector2f(700, 50)));
    //enemy.push_back(RedEnemy(sf::Vector2f(600, 50)));
    //enemy.push_back(RedEnemy(sf::Vector2f(500, 50)));
    hud.Update(player);
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

bool Map::MoveCollision(Entity &entity, double time) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        if (entity.CheckCollisionX(*i, time)) {
            while (entity.CheckCollisionX(*i, time)) {
                if (abs(entity.GetVelocity().x) < 1e-7f) {
                    entity.SetVelosityX(0);
                    break;
                }
                entity.SetVelosityX(entity.GetVelocity().x / 2.0);
            }
            return true;
        }
    }

    return false;
}

void Map::FallCollision(Entity &entity, double time) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        if (entity.CheckCollisionY(*i, time)) {
            while (entity.CheckCollisionY(*i, time)) {
                if (abs(entity.GetVelocity().y) < 1e-3f) {
                    if (entity.GetVelocity().y > 0.f) {
                        entity.SetOnGround(true);
                    }
                    entity.SetVelosityY(0.f);
                    return;
                }
                entity.SetVelosityY(entity.GetVelocity().y / 2.0f);
            }
            return;
        }
    }
    entity.SetOnGround(false);
}

void Map::EnemyHandlerAI(double time) {
    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        if (i->GetPos().x < player.GetPos().x) {
            i->SetVelosityX(0.2);
        }
        else {
            i->SetVelosityX(-0.2);
        }
        if (MoveCollision(*i, time)) {
            i->Jump(-0.5);
        }
    }
}

sf::Vector2f Map::GetRandomNewEnemyPos() {
    return sf::Vector2f();
}

Window* Map::EventListener(sf::RenderWindow* window, sf::Event event, double time) {

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            return new MainMenu(screen, font);
            break;
        case sf::Keyboard::Num1:
            player.SetGun(new AK());
            break;
        case sf::Keyboard::Num2:
            player.SetGun(new M4());
            break;
        case sf::Keyboard::Num3:
            player.SetGun(new AWP());
            break;
        default:
            break;
        }
        hud.Update(player);
    }

    return nullptr;
}

void Map::Draw(sf::RenderWindow* window) {
    hud.Draw(window);
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

    if (spawn_timer.getElapsedTime().asSeconds() > 3) {
        enemy.push_back(factory.GiveMe(GetRandomNewEnemyPos()));
        spawn_timer.restart();
    }

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
        player.SetVelosityX(-0.4);
        MoveCollision(player, time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.SetVelosityX(0.4);
        MoveCollision(player, time);
    }
    else {
        player.SetVelosityX(0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.Jump(-0.8);
    }
    
    FallCollision(player, time);

    player.Move(time);

    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        FallCollision(*i, time);
    }

    EnemyHandlerAI(time);

    for (auto i = enemy.begin(); i != enemy.end(); i++) {
        i->Move(time);
        if (player.EnemyInside(*i)) {
            player.ChangeHp(-(i->GetDamage()));
            hud.Update(player);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouse = sf::Mouse::getPosition(*window);
        Ammo* tmp = player.Fire(GetVector(player.GetPos() + player.size / 2.f, mouse));
        if (tmp) {
            ammo.push_back(*tmp);
            delete tmp;
        }
    }
}