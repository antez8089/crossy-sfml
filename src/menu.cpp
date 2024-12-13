#include "headers/game.h"

Menu::Menu() : selected_button_index(0), active(true){

}

Menu::~Menu(){

}

int Menu::get_button_pressed(){
    return selected_button_index;
}

void Menu::set_active( bool is_active){
    this->active = is_active;
}

void Menu::move_up(){
    if (selected_button_index > 0) {
        buttons[selected_button_index ].setFillColor(sf::Color::Blue);
        --selected_button_index;
        buttons[selected_button_index ].setFillColor(sf::Color::Cyan);
    } else {
        buttons[selected_button_index ].setFillColor(sf::Color::Blue);
        selected_button_index = buttons.size() -1;
        buttons[selected_button_index ].setFillColor(sf::Color::Cyan);
    }
}

void Menu::move_down(){
    if (selected_button_index != buttons.size() -1) {
        buttons[selected_button_index ].setFillColor(sf::Color::Blue);
        ++selected_button_index;
        buttons[selected_button_index].setFillColor(sf::Color::Cyan);
    } else {
        buttons[selected_button_index].setFillColor(sf::Color::Blue);
        selected_button_index = 0;

        buttons[selected_button_index].setFillColor(sf::Color::Cyan);
    }
}

void Menu::draw(sf::RenderWindow* window)
{
    window->draw(background);
    window->draw(title);
    for(auto& button : buttons)
    {
        window->draw(button);
    }
}

void Menu::run(sf::RenderWindow* window) {
    init_menu(window);
    while (window->isOpen()) {
        update_events(window);
        window->clear();
        draw(window);
        window->display();
        if (exit || !active) {
            return;
        }
    }
}

bool Menu::is_exit() const{
    return exit;
}



void Menu::init_menu(sf::RenderWindow* window)
{
    font.loadFromFile("assets/Michelin Bold.ttf");


    background_texture.loadFromFile("assets/back.jpg");
  
    background.setTexture(background_texture);
    background.setPosition(0, 0);
    background.setScale(
        window->getDefaultView().getSize().x / background_texture.getSize().x,
        window->getDefaultView().getSize().y / background_texture.getSize().y
    );

    title.setString("CROSSYROAD");
    title.setFont(font);
    title.setCharacterSize(70);
    title.setFillColor(sf::Color::Blue);
    title.setPosition(window->getDefaultView().getSize().x / 2 - 20, window->getDefaultView().getSize().y / 2 - 200);
    title.setOrigin(
        title.getGlobalBounds().width / 2,
        title.getGlobalBounds().height / 2
    );

    sf::Text play_button("New game", font, 50);
    play_button.setPosition(window->getDefaultView().getSize().x / 2 - 20, window->getDefaultView().getSize().y / 2);
    play_button.setFillColor(
        sf::Color::Cyan
    );
    play_button.setOrigin(
        play_button.getGlobalBounds().width / 2,
        play_button.getGlobalBounds().height / 2
    );

    sf::Text exit_button("Exit", font, 50);
    exit_button.setPosition(window->getDefaultView().getSize().x / 2 - 20, window->getDefaultView().getSize().y / 2 + 100);
    exit_button.setFillColor(
        sf::Color::Blue
    );

    exit_button.setOrigin(
        exit_button.getGlobalBounds().width / 2,
        exit_button.getGlobalBounds().height / 2
    );

    buttons.push_back(play_button);
    buttons.push_back(exit_button);


}


void Menu::update_events(sf::RenderWindow* window)
{
    while (window->pollEvent(menuevent)) {
        if (menuevent.type == sf::Event::Closed) {
            window->close();
        }
        if(menuevent.type == sf::Event::KeyPressed)
        {
            if (menuevent.key.code == sf::Keyboard::Escape){
                window->close();
            }
            else if(menuevent.key.code == sf::Keyboard::Up)
            {
                move_up();
            }
            else if(menuevent.key.code == sf::Keyboard::Down)
            {
                move_down();
            }
            else if(menuevent.key.code == sf::Keyboard::Enter)
            {
                if(get_button_pressed() == 0)
                {
                    active = false;
                }
                else if(get_button_pressed() == 1)
                {
                    exit = true;
                    window->close();
                }
            }
        }
    }
}