
#include "MapEditor.hpp"

class MainWindow {
private:

    sf::RenderWindow* window;
    Window* current_window;
    sf::Clock clock;
    sf::Event event;

public:

    MainWindow(const char* name, unsigned int width, unsigned int height);
    ~MainWindow();

    void Start();
};