
#include "MapEditor.hpp"

#include <iostream>
#include <iterator>

MapEditor::MapEditor(sf::Vector2u screen) : curs_model(sf::Vector2f(0, 0), sf::Vector2f(50, 50), sf::Color(190, 190, 190)) {
    blocks.clear();
    blocks.push_back(Block(sf::Vector2f(-50, 0), sf::Vector2f(50, screen.y)));
    blocks.push_back(Block(sf::Vector2f(0, screen.y), sf::Vector2f(screen.x, 50)));
    blocks.push_back(Block(sf::Vector2f(screen.x, 0), sf::Vector2f(50, screen.y)));
    blocks.push_back(Block(sf::Vector2f(0, -50), sf::Vector2f(screen.x, 50)));

    Load("./asd.asd");
}

MapEditor::~MapEditor() {
    //delete map;
}

int MapEditor::InOtherBlock(sf::Vector2i where) {
    Block tmp(sf::Vector2f(where.x - curs_model.GetSize().x / 2, where.y - curs_model.GetSize().y / 2), curs_model.GetSize());
    unsigned int k = 0;
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        for (size_t j = 0; j < tmp.GetBody().getVertexCount(); j++) {
            if (i->InBlock(sf::Vector2f(tmp.GetBody()[j].position.x, tmp.GetBody()[j].position.y))) {
                return k + 1;
            }
        }
        k++;
    }
    return 0;
}

sf::Vector2i MapEditor::SnapToGrid(sf::Vector2i pos) {
    sf::Vector2i tmp;
    tmp.x = pos.x / 25;
    tmp.y = pos.y / 25;
    
    tmp.x = (int)tmp.x * 25;
    tmp.y = (int)tmp.y * 25;

    return tmp;
}

void MapEditor::SetBlock(sf::Vector2i where) {
    blocks.push_back(Block(sf::Vector2f(where.x - curs_model.GetSize().x / 2, where.y - curs_model.GetSize().y / 2), curs_model.GetSize()));
}

void MapEditor::EventListener(sf::RenderWindow* window, sf::Event event, double time) {
    switch (event.type) {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::B) {
            std::cout << "you try to save map" << std::endl;
            Save("./asd.asd");
        }
        if (event.key.code == sf::Keyboard::R) {
            auto iterator = blocks.begin();
            std::advance(iterator, 4);
            blocks.erase(iterator, blocks.end());
        }
        break;
    default:
        break;
    }
}

void MapEditor::PermanentsEvents(sf::RenderWindow* window, double time) {

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!InOtherBlock(SnapToGrid(mouse_pos))) {
            SetBlock(SnapToGrid(mouse_pos));
        }
    }

    if (InOtherBlock(mouse_pos)) {
        curs_model.SetColor(sf::Color(0, 0, 0, 0));
    } 
    else {
        curs_model.SetColor(sf::Color(190, 190, 190, 255));
    }

    sf::Vector2f tmp_pos(SnapToGrid(sf::Vector2i(mouse_pos.x - curs_model.GetSize().x / 2, mouse_pos.y - curs_model.GetSize().y / 2)));
    curs_model.SetPosition(tmp_pos);

}

void MapEditor::Draw(sf::RenderWindow* window) {
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        i->Draw(window);
    }
    curs_model.Draw(window);
}

void MapEditor::Save(const char* file_name) {
    std::fstream file(file_name, std::ios::in | std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cout << "file not created" << std::endl;
        return;
    }
    std::size_t count = blocks.size();
    file.write((char*)&count, sizeof(std::size_t));
    for (auto i = blocks.begin(); i != blocks.end(); i++) {
        i->SaveTo(file);
    }
    file.close();
}

void MapEditor::Load(const char* file_name) {
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