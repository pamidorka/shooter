
#include <SFML/Graphics.hpp>
#include <fstream>

#ifndef BLOCK
#define BLOCK

class Block {
private:

    sf::Vector2f position;
    sf::Vector2f bl_size;
    sf::VertexArray vrt;

    void ResetVertex();

public:

    const static float eps;

    Block(sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::Black);
    Block() = delete;
    ~Block();

    void Draw(sf::RenderWindow* window);
    bool InBlock(sf::Vector2f where);
    void SaveTo(std::fstream &file); 
    void LoadFrom(std::fstream &file);
    void SetPosition(sf::Vector2f pos);
    void SetColor(sf::Color color);
    bool Intersects(Block& block);

    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();
    sf::VertexArray GetBody();

};

#endif