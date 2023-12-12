#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>


#include "Ball.h"  // Include the header file for the Ball class
#include "utilityFunctions.h" // Include the header file for the collision_wrangler function
using namespace std;

int main()
{
	sf::Vector2i screen_size; //I'm usig this handy Vector2i to store the screen width and heigth.
	screen_size.x = 800;
	screen_size.y = 800;
	sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "balls");

	vector <Ball*> all_my_balls; 
	all_my_balls.clear();

	//a vector to keep track of collisions. Used in game loop. Both ball objects are stored as a pair (taking advantage of the c++ pair command that lets you store two things in one variable.)
	vector <pair<Ball*, Ball*>> collisions; 
	collisions.clear(); 

	Ball* my_ball;
	for (int x = 0; x < 5 ; x++) {
		my_ball = new Ball(screen_size);
		all_my_balls.push_back(my_ball);
	}

	sf::CircleShape ball_shape_holder; //this is just a holder for drawing the balls. We'll change its position and radius and color each time we draw a ball.

	sf::Clock clock; 
	sf::Time elapsed;

	int split = 0;
	sf::Event event;
	bool clicked = false;

	while (window.isOpen())
	{
		elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds() < 17) { continue; } //this is the game loop. It will run every 17 milliseconds, or roughly 60 times per second.
		window.clear(sf::Color(100, 50, 180));
		//GENERIC UPDATE LOOP
		while (window.pollEvent(event)) //this is the event loop. It will run every time the user does something, like move the mouse or click on the window.
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					clicked = !clicked; // Toggle the clicked state
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
				if (all_my_balls.size() > 0) {
					Ball* last_ball = all_my_balls.back();
					delete last_ball;
					all_my_balls.pop_back(); 
				}
				
			}
		}

		
		Ball* newBall = new Ball(screen_size);

		// Set its initial position to the cursor position
		if (split % 10 == 0 && clicked == true) { 
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			newBall->pos.x = mousePosition.x;
			newBall->pos.y = mousePosition.y;
			// Add the new ball to the vector
			all_my_balls.push_back(newBall);
		}
	
		for (auto x : all_my_balls) {
			x->update(elapsed); //passing our elapsed time to the update function
		}
		//COLLISION STUFF
		collisions.clear();
		float distance;
		for (int a = 0; a < all_my_balls.size() - 1; a++) {
			for (int b = a + 1; b < all_my_balls.size(); b++) {
				//take the distance between the two balls using pythogoreans theorem:
				// Sqrt of difference of x plus the differnce of y
				distance = pow(
					(
						(all_my_balls[a]->pos.x - all_my_balls[b]->pos.x) *
						(all_my_balls[a]->pos.x - all_my_balls[b]->pos.x)
						)
					+ (
						(all_my_balls[a]->pos.y - all_my_balls[b]->pos.y) *
						(all_my_balls[a]->pos.y - all_my_balls[b]->pos.y)
						),
					0.5); //this is the DISTANCE between two balls. It is square root, imagine x^1/2

				//if the distance is less than the two balls' radii added togther, they must be touching, so stick it in collision vector.
				if (distance < all_my_balls[a]->radius + all_my_balls[b]->radius) {
					collisions.push_back(pair<Ball*, Ball*>(all_my_balls[a], all_my_balls[b]));
				}
			}
		}
		//now that we have our collisions, we need to deal with them.
		//To keep this game loop from getting too cluttered, we'll send it off to a function
		//and deal with them there.
		for (auto x : collisions) {
			collision_wrangler(x.first, x.second);
		}
		//DRAWING LOOP
		for (auto x : all_my_balls) {
			ball_shape_holder.setRadius(x->radius);
			ball_shape_holder.setPosition(x->pos);
			ball_shape_holder.setFillColor(x->col);
			ball_shape_holder.setOrigin(x->radius, x->radius); // This shift things down one and to the right so that SFML draws the circle with 'pos' being at the cetner.
			window.draw(ball_shape_holder);
		}
		window.display();
		
		clock.restart(); //restarts the clock
		split++;

	}
	return 0;
}

