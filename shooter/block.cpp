
#include "block.hpp"

#include <iostream>

void Block::ResetVertex() {
    vrt[0].position = position;

    vrt[1].position.x = position.x + bl_size.x;
    vrt[1].position.y = position.y;

    vrt[2].position.x = position.x + bl_size.x;
    vrt[2].position.y = position.y + bl_size.y;

    vrt[3].position.x = position.x;
    vrt[3].position.y = position.y + bl_size.y;
}

Block::Block(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {

    vrt = sf::VertexArray(sf::PrimitiveType::Quads, 4);

    bl_size = size;
    position = pos;
   
    ResetVertex();

    for (unsigned int i = 0; i < 4; i++) {
        vrt[i].color = color;
    }

}

Block::~Block() {
    // cock and balls.
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

void Block::SetPosition(sf::Vector2f pos) {
    position = pos;
    ResetVertex();
}

void Block::SetColor(sf::Color color) {
    for (unsigned int i = 0; i < vrt.getVertexCount(); i++) {
        vrt[i].color = color;
    }
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
    if ((position.x + bl_size.x > where.x) && (position.y + bl_size.y > where.y) && (where.x > position.x) && (where.y > position.y)) {
        return true;
    }
    return false;
}

void Block::Draw(sf::RenderWindow* window) {
    window->draw(vrt);
}