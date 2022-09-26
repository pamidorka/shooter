
#include "MainWindow.hpp"

int main() {
    MainWindow* window = new MainWindow("Shooter", 1000, 800);
    window->Start();
    delete window;
    exit(EXIT_SUCCESS);
}