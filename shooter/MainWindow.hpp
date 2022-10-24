
#include "MapEditor.hpp"
#include "MainMenu.hpp"

class MainWindow {
private:

    sf::RenderWindow* window;
    Window* current_window;
    sf::Clock clock;
    sf::Event event;
    sf::Font font;

public:

    MainWindow(const char* name, unsigned int width, unsigned int height);
    ~MainWindow();

    void Start();
};