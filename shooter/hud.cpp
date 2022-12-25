
#include "hud.hpp"

#include <iostream>

HUD::HUD(sf::Vector2f pos, sf::Font* load_font) {

	font = load_font;

	hp_text.setFont(*font);
	gun_text.setFont(*font);

	hp_text.setCharacterSize(30);
	gun_text.setCharacterSize(30);

	hp_text.setFillColor(sf::Color::Black);
	gun_text.setFillColor(sf::Color::Black);

	hp_text.setPosition(pos);
	gun_text.setPosition(sf::Vector2f(pos.x + hp_text.getGlobalBounds().width + 100, pos.y));
}

void HUD::Update(const Player& player) {
	hp_count = "hp: " + std::to_string(player.GetHp());
	gun_name = "gun: " + player.GetGunName();

	hp_text.setString(hp_count);
	gun_text.setString(gun_name);
}

void HUD::Draw(sf::RenderWindow* window) {
	window->draw(gun_text);
	window->draw(hp_text);
}
