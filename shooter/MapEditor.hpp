
#include "map.hpp"
#include "Window.hpp"

class MapEditor : public Window {
private:

    std::vector<Block> blocks;
    
    void SetBlock(sf::Vector2i where);
    int InBlock(sf::Vector2i where);
    int InOtherBlock(sf::Vector2i where);
    void MoveBlock(sf::Vector2i where);

public:

    MapEditor();
    ~MapEditor() override;

    void Save(const char* file_name);
    void Load(const char* file_name);

    void EventListener(sf::RenderWindow* window, sf::Event event, double time) override; 
    void Draw(sf::RenderWindow* window) override;

};