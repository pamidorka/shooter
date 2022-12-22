
#include "map.hpp"
#include "Window.hpp"

class MapEditor : public Window {
private:

    std::list<Block> blocks;
    Block curs_model;

    sf::Font* font;
    
    void SetBlock(sf::Vector2i where);
    int InOtherBlock(sf::Vector2i where);
    sf::Vector2i SnapToGrid(sf::Vector2i pos);
    int MouseInBlock(sf::Vector2i where);
    void MoveBlock(sf::Vector2i where);

public:

    MapEditor(sf::Vector2u screen, sf::Font* load_font);
    ~MapEditor() override;

    void Save(const char* file_name);
    void Load(const char* file_name);

    Window* EventListener(sf::RenderWindow* window, sf::Event event, double time) override; 
    void PermanentsEvents(sf::RenderWindow* window, double time);
    void Draw(sf::RenderWindow* window) override;

};