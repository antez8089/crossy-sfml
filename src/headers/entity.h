#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class Entity
{
    protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    public:
    Entity();
    virtual ~Entity();
    void move();
    virtual void render(sf::RenderWindow* window);
    virtual void update(const float& dt);

};


#endif