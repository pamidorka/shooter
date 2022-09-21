
#include "block.hpp"

#include <iostream>

Block::Block(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {

    vrt = sf::VertexArray(sf::PrimitiveType::Quads, 4);

    bl_size = size;
    position = pos;
    
    vrt[0].position = pos;

    vrt[1].position.x = pos.x + size.x;
    vrt[1].position.y = pos.y;

    vrt[2].position.x = pos.x + size.x;
    vrt[2].position.y = pos.y + size.y;

    vrt[3].position.x = pos.x;
    vrt[3].position.y = pos.y + size.y;

    for (unsigned int i = 0; i < 4; i++) {
        vrt[i].color = color;
    }

}

Block::~Block() {
    
}

void Block::SaveTo(std::fstream &file) {
    file.write((char*)&position, sizeof(sf::Vector2f));
    file.write((char*)&bl_size, sizeof(sf::Vector2f));
}

void Block::LoadFrom(std::fstream &file) {
    file.read((char*)&position, sizeof(sf::Vector2f));
    file.read((char*)&bl_size, sizeof(sf::Vector2f));

    vrt[0].position = position;

    vrt[1].position.x = position.x + bl_size.x;
    vrt[1].position.y = position.y;

    vrt[2].position.x = position.x + bl_size.x;
    vrt[2].position.y = position.y + bl_size.y;

    vrt[3].position.x = position.x;
    vrt[3].position.y = position.y + bl_size.y;
}

sf::Vector2f Block::GetPosition() {
    return position;
}

sf::Vector2f Block::GetSize() {
    return bl_size;
}

sf::VertexArray Block::GetBody() {
    return vrt;
}

bool Block::InBlock(sf::Vector2f where) {
    if ((position.x + bl_size.x >= where.x) && (position.y + bl_size.y >= where.y) && (where.x >= position.x) && (where.y >= position.y)) {
        return true;
    }
    return false;
}

void Block::Draw(sf::RenderWindow* window) {
    window->draw(vrt);
}