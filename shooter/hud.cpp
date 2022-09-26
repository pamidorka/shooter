#include "hud.hpp"

#include <iostream>

HUD::HUD() {

}

HUD::HUD(Player& player, sf::Vector2f pos) {
	this->player = &player;

	font.loadFromFile("./OpenSans-Regular.ttf");

	hp_text.setFont(font);
	gun_text.setFont(font);

	hp_text.setCharacterSize(30);
	gun_text.setCharacterSize(30);

	hp_text.setFillColor(sf::Color::Black);
	gun_text.setFillColor(sf::Color::Black);

	Update();

	hp_text.setPosition(pos);
	gun_text.setPosition(sf::Vector2f(pos.x + hp_text.getGlobalBounds().width + 50, pos.y));
}

void HUD::Update() {
	hp_count = std::string("hp: ") + std::to_string(player->GetHp());
	gun_name = "gun: ak";

	hp_text.setString(hp_count);
	gun_text.setString(gun_name);
}

void HUD::Draw(sf::RenderWindow* window) {
	window->draw(gun_text);
	window->draw(hp_text);
}
