#pragma once
#include <SFML/Graphics.hpp>

class Ball{
public:
    Ball(sf::Vector2i screen);
    void update(sf::Time delta_t);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2i screen_size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f gravity;
    sf::Color col;
    float radius;
    float mass;
    float restitution;

};

