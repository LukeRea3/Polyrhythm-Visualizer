#include "Ball.h"
#include <cstdlib>

Ball::Ball(sf::Vector2i screen) : screen_size(screen), mass(0), restitution(0) {
    gravity = sf::Vector2f(0.0f, 500.0f);
    pos.x = rand() % (screen.x - 50) + 50;
    pos.y = rand() % (screen.y - 50) + 50;

    vel.x = rand() % 180 - 90;
    vel.y = rand() % 180 - 90; 

    radius = rand() % 5 + 10;
    col = sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

void Ball::update(sf::Time delta_t) {
    vel.x += gravity.x * delta_t.asSeconds();
    vel.y += gravity.y * delta_t.asSeconds();

    pos.x = pos.x + (vel.x * delta_t.asSeconds());
    pos.y = pos.y + (vel.y * delta_t.asSeconds());

    if (((pos.x < radius) && (vel.x < 0)) || ((pos.x > screen_size.x - radius) && (vel.x > 0))) { vel.x = -vel.x; }
    if (((pos.y < radius) && (vel.y < 0)) || ((pos.y > screen_size.y - radius) && (vel.y > 0))) { vel.y = -vel.y; }
}

void Ball::draw(sf::RenderWindow& window) const {
    sf::CircleShape ball_shape_holder(radius);
    ball_shape_holder.setPosition(pos);
    ball_shape_holder.setFillColor(col);
    ball_shape_holder.setOrigin(radius, radius);
    window.draw(ball_shape_holder);
}