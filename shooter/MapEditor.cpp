
#include "MapEditor.hpp"

#include <iostream>

MapEditor::MapEditor() {
    Load("./asd.asd");
}

MapEditor::~MapEditor() {
    //delete map;
}

int MapEditor::InBlock(sf::Vector2i where) {
    for(size_t i = 0; i < blocks.size(); i++) {
        if ((blocks[i].InBlock(sf::Vector2f(where.x, where.y)))) {
            return i + 1;
        }
    }
    return 0;
}

int MapEditor::InOtherBlock(sf::Vector2i where) {
    Block tmp(sf::Vector2f(where.x - 25, where.y - 25), sf::Vector2f(50, 50), sf::Color::Black);
    for (size_t i = 0; i < blocks.size(); i++) {
        for (size_t j = 0; j < tmp.GetBody().getVertexCount(); j++) {
            if (blocks[i].InBlock(sf::Vector2f(tmp.GetBody()[j].position.x, tmp.GetBody()[j].position.y))) {
                return i + 1;
            }
        }
    }
    return 0;
}

void MapEditor::SetBlock(sf::Vector2i where) {
    blocks.push_back(Block(sf::Vector2f(where.x - 25, where.y - 25), sf::Vector2f(50, 50), sf::Color::Black));
}

void MapEditor::EventListener(sf::RenderWindow* window, sf::Event event, double time) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        if (!InBlock(sf::Mouse::getPosition(*window)) && !InOtherBlock(sf::Mouse::getPosition(*window))) {
            SetBlock(sf::Mouse::getPosition(*window));
        }
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == 0x01) {
            std::cout << "you try to save map" << std::endl;
            Save("./asd.asd");
        }
        break;
    default:
        break;
    }
}

void MapEditor::Draw(sf::RenderWindow* window) {
    for (size_t i = 0; i < blocks.size(); i++) {
        blocks[i].Draw(window);
    }
}

void MapEditor::Save(const char* file_name) {
    std::fstream file(file_name, std::ios::in | std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cout << "file not created" << std::endl;
        return;
    }
    std::size_t count = blocks.size();
    file.write((char*)&count, sizeof(std::size_t));
    for (std::size_t i = 0; i < count; i++) {
        blocks[i].SaveTo(file);
    }
    file.close();
}

void MapEditor::Load(const char* file_name) {
    blocks.clear();
    std::fstream file(file_name, std::ios::in | std::ios::out);
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