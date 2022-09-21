
#include <SFML/Graphics.hpp>
#include <fstream>

class Block {
private:

    sf::Vector2f position;
    sf::Vector2f bl_size;
    sf::VertexArray vrt;

public:

    Block(sf::Vector2f pos, sf::Vector2f size, sf::Color color = sf::Color::Black);
    Block(sf::Vector2f frt_pos, sf::Vector2f scd_pos, sf::Vector2f thr_pos, sf::Vector2f fr_pos, sf::Color color = sf::Color::Black);
    Block() = delete;
    ~Block();

    void Draw(sf::RenderWindow* window);
    bool InBlock(sf::Vector2f where);
    void SaveTo(std::fstream &file); 
    void LoadFrom(std::fstream &file);

    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();
    sf::VertexArray GetBody();

};