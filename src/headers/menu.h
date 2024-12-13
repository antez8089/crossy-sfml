#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>


class Menu 
{
    protected:
        sf::Sprite background;
        sf::Texture background_texture;
        sf::Event menuevent;
        sf::Font font;
        sf::Text title;
        std::vector<sf::Text> buttons;
        bool exit = false;
        bool active = true;
        int selected_button_index;
    public:
        Menu();
        ~Menu();
        int get_button_pressed();
        void move_up();
        void move_down();
        void init_menu(sf::RenderWindow* window);
        void update_events(sf::RenderWindow* window);
        void draw(sf::RenderWindow* window);
        void run(sf::RenderWindow* window);
        bool is_exit() const;
        void set_active(bool avtive);
};

#endif