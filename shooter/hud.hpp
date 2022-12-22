
#include <SFML/Graphics.hpp>

#include "player.hpp"

#ifndef HUD__
#define HUD__

class HUD {
private:

	sf::Font font;

	std::string gun_name;
	std::string hp_count;

	sf::Text gun_text;
	sf::Text hp_text;


public:
	
	HUD(sf::Vector2f pos);

	void Update(const Player& player);
	void Draw(sf::RenderWindow* window);

};

#endif

