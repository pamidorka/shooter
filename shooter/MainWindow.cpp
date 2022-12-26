
#include "MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow(const char* name, unsigned int width, unsigned int height) {

    if (!font.loadFromFile("OpenSans-Regular.ttf")) {
        std::cout << "font not loaded, exit" << std::endl;
        exit(EXIT_FAILURE);
    }

    window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close);
    current_window = new MainMenu(sf::Vector2u(width, height), &font);

}

MainWindow::~MainWindow() {
    delete window;
    delete current_window;
}

void MainWindow::Start() {

    while(window->isOpen()) {
        double time = clock.restart().asMicroseconds() / 800.0;
        if (time > 50.0) { continue; }
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else {
                Window* temp = current_window->EventListener(window, event, time);
                if (temp) {
                    delete current_window;
                    current_window = temp;
                    time = 0;
                }
            }
        }
        Window* temp = current_window->PermanentsEvents(window, time);
        if (temp) {
            delete current_window;
            current_window = temp;
            time = 0;
        }
        window->clear(sf::Color::White);
        current_window->Draw(window);
        window->display();
    }
}