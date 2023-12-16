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

#include <SFML/OpenGL.hpp>

#include "Ball.h"  // Include the header file for the Ball class
using namespace std; 




int main()
{
	sf::Vector2i screen_size; //I'm usig this Vector2i to store the screen width and heigth.
	screen_size.x = 800;
	screen_size.y = 800;
	sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Balls on square");

	vector <Ball*> all_my_balls; 

	all_my_balls.clear();

	//a vector to keep track of collisions. Used in game loop. Both ball objects are stored as a pair (taking advantage of the c++ pair command that lets you store two things in one variable.)
	vector <pair<Ball*, Ball*>> collisions; 
	collisions.clear(); 

	Ball* my_ball; 

	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(240, 450), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(260, 470), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(280, 490), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(300, 510), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(320, 530), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(340, 550), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(360, 570), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(380, 590), sf::Vector2f(-80, 35)));
	all_my_balls.push_back(new Ball(screen_size, sf::Vector2f(400, 610), sf::Vector2f(-80, 35)));

	//for (int x = 0; x < 5 ; x++) {
	//	my_ball = new Ball(screen_size);
	//	all_my_balls.push_back(my_ball); 
	//}

	//LINE DRAWING STUFF 
	
	sf::Vector2f lineA(400, 500);
	sf::Vector2f lineB(200, 300);

	sf::Vector2f LineC(400, 500);
	sf::Vector2f LineD(600, 300);

	sf::Vertex Leftline[] =
	{
		sf::Vertex(lineA),
		sf::Vertex(lineB)
	};

	sf::Vertex Rightline[] =
	{
		sf::Vertex(LineC),
		sf::Vertex(LineD)
	};

	//END LINE DRAWING STUFF

	sf::CircleShape ball_shape_holder; //this is just a holder for drawing the balls. We'll change its position and radius and color each time we draw a ball.

	sf::CircleShape trig_ball_holder; //holder for my trig balls
	vector<TrigBall*> all_my_trig_balls;


	//linear speed = angular speed * radius

	all_my_trig_balls.clear();
	
	//radiusX, radiusY, initSpeedMultiplier (CHANGE THIS TO NEGATIVE WHEN COLLISON, inital position, motion radius)

	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.25,  sf::Vector2f(400,500), 40));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.30,  sf::Vector2f(400,500), 60));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.35,  sf::Vector2f(400,500), 80));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.40,  sf::Vector2f(400,500), 100));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.45,  sf::Vector2f(400,500), 120));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.50,  sf::Vector2f(400,500), 140));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.55,  sf::Vector2f(400,500), 160));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.60,  sf::Vector2f(400,500), 180));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.65,  sf::Vector2f(400,500), 200));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.70,  sf::Vector2f(400,500), 220));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.75,  sf::Vector2f(400,500), 240));


	sf::Clock clock; 
	sf::Time elapsed;


	//SIN COS CIRCLE TEST
	




	int split = 0;
	sf::Event event;
	bool clicked = false;

	//WHILE WINDOW LOOP

	while (window.isOpen())
	{
		elapsed = clock.getElapsedTime(); //get the elapsed time since the clock was last restarted. This is a time object, which is a bit of a pain to work with. 
		if (elapsed.asMilliseconds() < 17) { continue; } //this is the game loop. It will run every 17 milliseconds, or roughly 60 times per second.
		//window.clear(sf::Color(0,0,0));
		//GENERIC UPDATE LOOP


		

		//Ball* newBall = new Ball(screen_size);

		// Set its initial position to the cursor position
		//if (split % 10 == 0 && clicked == true) {
			//sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			//newBall->pos.x = mousePosition.x;
			//newBall->pos.y = mousePosition.y;
			// Add the new ball to the vector
			//all_my_balls.push_back(newBall);
		//}

		
		
	
		

		//COLLISION STUFF
		collisions.clear();

		//DRAWING LOOP
		
		window.draw(Leftline, 2, sf::Lines);
		window.draw(Rightline, 2, sf::Lines);

		//TRIG BALL STUFF  

		for (auto x : all_my_trig_balls) {
			x->update(elapsed); //passing our elapsed time to the update function
		}
		for (auto x : all_my_trig_balls) {
			x->draw(window);
		}
		

		//CIRCLE TEST DEMO
		


		window.display();


		//INCREASE ANGLE TEST
		
		clock.restart(); //restart the clock so that we can measure the time it takes to do the next frame.
		split++;
	}
	return 0;
}

