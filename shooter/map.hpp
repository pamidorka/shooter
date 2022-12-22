
#include "player.hpp"
#include "factory.hpp"
#include "block.hpp"
#include "Window.hpp"
#include "ammo.hpp"
#include "hud.hpp"

#include <list>

#ifndef MAP__
#define MAP__

class Map : public Window {
private:

    //HUD hud;

    std::list<Block> blocks;
    std::list<Enemy> enemy;
    std::list<Ammo> ammo;

    sf::Font* font;
    
    Player player = Player(sf::Vector2f(100, Player::size.y));
    sf::Vector2u screen;

    sf::Vector2f GetVector(sf::Vector2f player_pos, sf::Vector2i mouse_pos);
    void MoveCollision(Entity& entity, double time);
    void FallCollision(Entity& entity, double time);
    void EnemyHandlerAI(double time);

public:

    Map(const char* from, sf::Vector2u size, sf::Font* load_font);
    Map(sf::Vector2u size, sf::Font* load_font); // empty map
    ~Map() override;

    Window* EventListener(sf::RenderWindow* window, sf::Event event, double time) override;
    void Draw(sf::RenderWindow* window) override;
    void PermanentsEvents(sf::RenderWindow* window, double time) override;

};

#endif 