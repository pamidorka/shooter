
#include <thread>
#include <mutex>
#include <condition_variable>

#include "MapEditor.hpp"

class MainWindow {
private:

    sf::RenderWindow* window;
    Window* current_window;
    double time;
    sf::Clock clock;
    sf::Event event;

    // std::thread th_ev;
    // std::thread th_en;
    // std::thread th_bl;

    // std::mutex mt_ev;
    // std::condition_variable cv_ev;
    // bool ev_wait;


    // void EventThread();
    // void EnemyThread();
    // void BulletThread();

public:

    MainWindow(const char* name, unsigned int width, unsigned int height);
    ~MainWindow();

    void Start();
};