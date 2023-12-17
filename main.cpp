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
#include <SFML/Audio.hpp>


#include "Ball.h"  // Include the header file for the Ball class
using namespace std; 




int main()
{

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Music Notes/D (1).wav")) {
		cout << "Error loading sound" << endl;
		return -1;
	}

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


	CyBall* cy_ball;

	vector <CyBall*> biglist;
	biglist.clear();
	float sss = 0;
	for (int x = 70; x < 280; x = x + 20) {
		sss = sss + 0.4;
	cy_ball = new CyBall(sf::Vector2f(400, 500), x,sss);
	biglist.push_back(cy_ball);
}

	//for (int x = 0; x < 5 ; x++) {
	//	my_ball = new Ball(screen_size);	
	//	all_my_balls.push_back(my_ball); 
	//}

	//LINE DRAWING STUFF 
	sf::Vector2f LineA(400, 500);
	sf::Vector2f LineB(200, 300);

	sf::Vector2f LineC(400, 500);
	sf::Vector2f LineD(600, 300);

	sf::Vertex Leftline[] =
	{
		sf::Vertex(LineA),
		sf::Vertex(LineB)
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

	//.24 
	//.26


	//all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.255,  sf::Vector2f(404,500), 40));
	//all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.265,  sf::Vector2f(403,500), 60));
	//all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.270,  sf::Vector2f(402,500), 80));
	/*
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.375,  sf::Vector2f(400,500), 10));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.280,  sf::Vector2f(400,500), 120));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.285,  sf::Vector2f(400,500), 140));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.290,  sf::Vector2f(400,500), 160));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.295,  sf::Vector2f(400,500), 180));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.300,  sf::Vector2f(400,500), 200));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.305,  sf::Vector2f(400,500), 220));
	all_my_trig_balls.push_back(new TrigBall(10.15, 10.15, 0.310,  sf::Vector2f(400,500), 240));

	
	sf::SoundBuffer buffer1;
	buffer1.loadFromFile("music notes/D (1).wav");
	all_my_trig_balls[0]->sound.setBuffer(buffer1);

	sf::SoundBuffer buffer2;
	buffer2.loadFromFile("music notes/D (2).wav");
	all_my_trig_balls[1]->sound.setBuffer(buffer2);

	sf::SoundBuffer buffer3;
	buffer3.loadFromFile("music notes/D (3).wav");
	all_my_trig_balls[2]->sound.setBuffer(buffer3);

	sf::SoundBuffer buffer4;
	buffer4.loadFromFile("music notes/D (4).wav");
	all_my_trig_balls[3]->sound.setBuffer(buffer4);

	sf::SoundBuffer buffer5;
	buffer5.loadFromFile("music notes/D (5).wav");
	all_my_trig_balls[4]->sound.setBuffer(buffer5);

	sf::SoundBuffer buffer6;
	buffer6.loadFromFile("music notes/D (6).wav");
	all_my_trig_balls[5]->sound.setBuffer(buffer6);

	sf::SoundBuffer buffer7;
	buffer7.loadFromFile("music notes/D (7).wav");
	all_my_trig_balls[6]->sound.setBuffer(buffer7);

	sf::SoundBuffer buffer8;
	buffer8.loadFromFile("music notes/D (8).wav");
	all_my_trig_balls[7]->sound.setBuffer(buffer8);

	//sf::SoundBuffer buffer9;
	//buffer9.loadFromFile("music notes/D (9).wav");
	//all_my_trig_balls[8]->sound.setBuffer(buffer9);

	//sf::SoundBuffer buffer10;
	//buffer10.loadFromFile("music notes/D (10).wav");
	//all_my_trig_balls[9]->sound.setBuffer(buffer10);

	//sf::SoundBuffer buffer11;
	//buffer11.loadFromFile("music notes/D (11).wav");
	//all_my_trig_balls[10]->sound.setBuffer(buffer11);

	*/
	
	sf::Clock clock; 
	sf::Time elapsed;


	//SIN COS CIRCLE TEST
	




	sf::Event event;
	bool clicked = false; 

	//WHILE WINDOW LOOP

	while (window.isOpen())
	{
		elapsed = clock.getElapsedTime(); //get the elapsed time since the clock was last restarted. This is a time object, which is a bit of a pain to work with. 
		if (elapsed.asMilliseconds() < 17) { continue; } //this is the game loop. It will run every 17 milliseconds, or roughly 60 times per second.
		window.clear(sf::Color(0,0,0));
		//GENERIC UPDATE LOOP

		//COLLISION STUFF
		collisions.clear();
		//DRAWING LOOP
		window.draw(Leftline, 2, sf::Lines);
		window.draw(Rightline, 2, sf::Lines);
		//TRIG BALL STUFF  
		for (auto x : all_my_trig_balls) {
			x->update(elapsed, LineA, LineB, LineC, LineD); //passing our elapsed time to the update function
		}
		for (auto x : all_my_trig_balls) {
	//		x->draw(window);
		}
		//CIRCLE TEST DEMO



		for (int yy = biglist.size() - 1; yy > 0;yy--){
			biglist[yy]->update(elapsed);
			biglist[yy]->draw(window);
		}
		window.display();
	
		clock.restart(); //restart the clock so that we can measure the time it takes to do the next frame.
	}
	return 0;
}

