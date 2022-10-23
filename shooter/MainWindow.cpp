
#include "MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow(const char* name, unsigned int width, unsigned int height) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close);
    //current_window = new Map("./asd.asd", sf::Vector2u(width, height));
    current_window = new MapEditor(sf::Vector2u(width, height));

}

MainWindow::~MainWindow() {
    delete window;
    delete current_window;
}

void MainWindow::Start() {

    while(window->isOpen()) {
        double time = clock.restart().asMicroseconds() / 800;
        if (time > 50.0) { continue; }
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else {
                current_window->EventListener(window, event, time);
            }
        }
        current_window->PermanentsEvents(window, time);
        window->clear(sf::Color::White);
        current_window->Draw(window);
        window->display();
    }
}