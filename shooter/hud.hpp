
#include <SFML/Graphics.hpp>

#include "player.hpp"

class HUD {
private:

	sf::Font font;

	std::string gun_name;
	std::string hp_count;

	sf::Text gun_text;
	sf::Text hp_text;

	Player* player;

public:
	
	HUD();
	HUD(Player& player, sf::Vector2f pos);

	void Update();
	void Draw(sf::RenderWindow* window);

};

