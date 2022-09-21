
#include "player.hpp"
#include "factory.hpp"
#include "block.hpp"
#include "Window.hpp"

class Map : public Window {
private:
    std::vector<Block> blocks;
    //std::vector<Enemy> enemy;
    Player player = Player(sf::Vector2<double>(0.0, 100));
    sf::Vector2u screen;

public:

    Map(const char* from, sf::Vector2u size);
    Map(sf::Vector2u size); // empty map
    ~Map() override;

    void EventListener(sf::RenderWindow* window, sf::Event event, double time) override;
    void Draw(sf::RenderWindow* window) override;
    void CollisionListener(double time) override;

};
