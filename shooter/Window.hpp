
#include <SFML/Graphics.hpp>

#ifndef WIN
#define WIN

class Window {
public:

    Window() = default;
    virtual ~Window();

    virtual Window* EventListener(sf::RenderWindow* window, sf::Event event, double time) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual Window* PermanentsEvents(sf::RenderWindow* window, double time) = 0;

};


#endif