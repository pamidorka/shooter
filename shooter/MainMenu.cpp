
#include "MainMenu.hpp"

const std::string MainMenu::sgb_text = "Start game";
const std::string MainMenu::eb_text = "Map Editor";
const std::string MainMenu::db_text = "Difficulty: ";

const ButtonColorSet MainMenu::ColorsDefaultBtn = ButtonColorSet(sf::Color(0x666666FF), sf::Color(0x888888FF), sf::Color(0xAAAAAAFF));
const ButtonColorSet MainMenu::ColorsDisabled = ButtonColorSet(sf::Color(0x660000FF), sf::Color(0xAA3333FF), sf::Color(0xFF5555FF));
const ButtonColorSet MainMenu::ColorsEnabled = ButtonColorSet(sf::Color(0x006600FF), sf::Color(0x119911FF), sf::Color(0x22BB22FF));

MainMenu::MainMenu(sf::Vector2u screen_size, const sf::Font* font) : start_game_btn(screen_size.x / 2.0 - 50, screen_size.y / 2.0 - 100, 100, 50, font, sgb_text, 12, ColorsDefaultBtn), editor_btn(screen_size.x / 2.0 - 50, screen_size.y / 2.0 - 25, 100, 50, font, eb_text, 12, ColorsDefaultBtn) {
	difficulty_btn = MultipleButtons();
	ToggleButton tmp(screen_size.x / 2.0 - 175, screen_size.y / 2.0 + 50, 100, 50, font, "Easy", "Easy", 12, ColorsEnabled, ColorsDisabled);
	difficulty_btn.AddButton(tmp);
	tmp = ToggleButton(screen_size.x / 2.0 - 50, screen_size.y / 2.0 + 50, 100, 50, font, "Normal", "Normal", 12, ColorsEnabled, ColorsDisabled);
	difficulty_btn.AddButton(tmp);
	tmp = ToggleButton(screen_size.x / 2.0 + 75, screen_size.y / 2.0 + 50, 100, 50, font, "Hard", "Hard", 12, ColorsEnabled, ColorsDisabled);
	difficulty_btn.AddButton(tmp);
}

void MainMenu::EventListener(sf::RenderWindow* window, sf::Event event, double time) {

}

void MainMenu::Draw(sf::RenderWindow* window) {
	start_game_btn.Render(window);
	editor_btn.Render(window);
	difficulty_btn.Render(window);
}

void MainMenu::PermanentsEvents(sf::RenderWindow* window, double time) {
	
}
