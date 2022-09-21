
#include <SFML/Graphics.hpp>

#ifndef WIN
#define WIN

class Window {
public:

    Window() = default;
    virtual ~Window();

    virtual void EventListener(sf::RenderWindow* window, sf::Event event, double time) = 0;
    virtual void Draw(sf::RenderWindow* window) = 0;
    virtual void CollisionListener(double time) = 0;

};


#endif