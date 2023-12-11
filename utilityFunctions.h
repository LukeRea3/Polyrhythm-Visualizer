#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"


float angle_of_a_vector(sf::Vector2f v);
float magnitude_of_a_vector(sf::Vector2f x);
void collision_wrangler(Ball* a, Ball* b);
