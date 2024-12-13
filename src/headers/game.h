#ifndef GAME_H
#define GAME_H
#include "entity.h"
#include "menu.h"

class Game 
{
    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::Clock clock;
        float dt;
        void init_window();
        Menu menu;

    public:
        Game();
        ~Game();
        void render();
        void update();
        void run();
        void update_events();
        void update_dt();
};
#endif