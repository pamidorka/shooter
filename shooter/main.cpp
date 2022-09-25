
#include "MainWindow.hpp"

int main() {
    MainWindow* window = new MainWindow("Shooter", 1000, 600);
    window->Start();
    delete window;
    exit(EXIT_SUCCESS);
}