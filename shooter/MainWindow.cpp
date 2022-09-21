
#include "MainWindow.hpp"

#include <iostream>

MainWindow::MainWindow(const char* name, unsigned int width, unsigned int height) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close);
    current_window = new Map(sf::Vector2u(width, height));

}

MainWindow::~MainWindow() {
    delete window;
    delete current_window;
}

// void MainWindow::EventThread() {
//     while(window->isOpen()) {
//         std::unique_lock lock(mt_ev);
//         cv_ev.wait(lock, [this]{ return ev_wait; });
//     }
// }

void MainWindow::Start() {
    //th_ev = std::thread(&MainWindow::EventThread, this);

    while(window->isOpen()) {
        time = (double)clock.restart().asMicroseconds() / 800.0;
        while(window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else {
                current_window->EventListener(window, event, time);
            }
        }
        current_window->CollisionListener(time);
        window->clear(sf::Color::White);
        current_window->Draw(window);
        window->display();
    }

    //th_ev.join();
}