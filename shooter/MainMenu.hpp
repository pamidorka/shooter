
#include "Window.hpp"
#include "Buttons/MultipleButtons.hpp"

#ifndef  MAIN_MENU__
#define  MAIN_MENU__

class MainMenu : public Window {
private:

    Button start_game_btn;
    Button editor_btn;
    MultipleButtons difficulty_btn;

public:

    static const std::string sgb_text;
    static const std::string eb_text;
    static const std::string db_text;

    static const ButtonColorSet ColorsDefaultBtn;
    static const ButtonColorSet ColorsDisabled;
    static const ButtonColorSet ColorsEnabled;

    MainMenu(sf::Vector2u screen_size, const sf::Font* font);

    void EventListener(sf::RenderWindow* window, sf::Event event, double time) override;
    void Draw(sf::RenderWindow* window) override;
    void PermanentsEvents(sf::RenderWindow* window, double time) override;

};

#endif
