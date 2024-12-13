#include "headers/game.h"
#include <fstream>

Game::Game(){
    init_window();
}

Game::~Game(){
    delete window;
}

void Game::init_window(){
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Cross the Road");
}

void Game::update_dt() {
    dt = clock.restart().asSeconds();
}


void Game::render() {
    window->clear();
    window->display();
}

void Game::update() {
    update_events();
}

void Game::update_events() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window->close();
        }
        if (event.key.code == sf::Keyboard::Escape){
            window->close();
        }
        
    }
}

void Game::run() {
    while (window->isOpen()) {
        menu.run(window);
        update_dt();
        update();
        render();
    }
}

