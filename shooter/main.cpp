
#include "MainWindow.hpp"

int main() {
    MainWindow* window = new MainWindow("Shooter", 800, 600);
    window->Start();
    delete window;
    exit(EXIT_SUCCESS);
}