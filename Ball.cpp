#include "Ball.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>  
#include <SFML/Audio.hpp>



bool is_line(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C){ 
     return (B.x - A.x) * ((C.y+7) - A.y) - (B.y - A.y) * ((C.x) - A.x) > 0;
}



Ball::Ball(sf::Vector2i screen,sf::Vector2f ipos, sf::Vector2f ivel) : screen_size(screen), pos(ipos), vel(ivel) {
    gravity = sf::Vector2f(0.0f, 20.0f);



   //pos.x = rand() % (screen.x - 50) + 50;
   // pos.y = rand() % (screen.y - 50) + 50;

   // vel.x = rand() % 180 - 90;
   // vel.y = rand() % 180 - 90; 

    radius = 7;
    col = sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

void Ball::update(sf::Time delta_t,sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D) {
    vel.x += gravity.x * delta_t.asSeconds();
    vel.y += gravity.y * delta_t.asSeconds();

    pos.x = pos.x + (vel.x * delta_t.asSeconds());
    pos.y = pos.y + (vel.y * delta_t.asSeconds());

    if (((pos.x < radius) && (vel.x < 0)) || ((pos.x > screen_size.x - radius) && (vel.x > 0))) { vel.x = -vel.x; }
    if (((pos.y < radius) && (vel.y < 0)) || ((pos.y > screen_size.y - radius) && (vel.y > 0))) { vel.y = -vel.y; }

    
    // Check collision with the V-shape
    if (
        (is_line(A, B, pos)&&pos.x>B.x)
            
           
        &&
        (is_line(D,C,pos)&&pos.x < D.x)
        )
        
   {
        col = sf::Color::Red; 
        
    }
    else {
        if (col == sf::Color::Red) { vel.x = -vel.x; vel.y = -vel.y; }
       	col = sf::Color::Green;
    }
}

void Ball::draw(sf::RenderWindow& window) const {
    sf::CircleShape ball_shape_holder(radius);
    ball_shape_holder.setPosition(pos);
    ball_shape_holder.setFillColor(col);
    ball_shape_holder.setOrigin(radius, radius);
    window.draw(ball_shape_holder);
}


//TRIG CLASS IMPLIMENTATION

    TrigBall::TrigBall(float radiusX, float radiusY,float initSpeedMultiplier,sf::Vector2f position, float motionRadius) : x(radiusX), y(radiusY), speedMultiplier(initSpeedMultiplier)
    {


        this->radius = 6;   
        this->color = sf::Color::Blue;
        this->x2 = 0;
        this->y2 = 0;
        this->pos = position;
        this->motionRadius = motionRadius;
    
    }

    void TrigBall::update(sf::Time delta_t,sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D) {
        x += 2.00f * speedMultiplier * (delta_t.asSeconds());
        y += 2.00f * speedMultiplier * ( delta_t.asSeconds());

        float sinX = std::sin(x);
        float cosY = std::cos(y);

        x2 = pos.x + (sinX) * motionRadius;  
        y2 = pos.y + (cosY) * motionRadius;

        //Check collision with the V-shape
     /*    if (!is_line(A, B, sf::Vector2f(x2, y2))) {
            speedMultiplier = -speedMultiplier;
            color = sf::Color::Blue;
            sound.play();   
        }
        else if (is_line(C, D, sf::Vector2f(x2, y2))) {
            speedMultiplier = -speedMultiplier;
            color = sf::Color::Green;
            sound.play();
        }*/
       
    }
    void TrigBall::draw(sf::RenderWindow& window){
        sf::CircleShape ball_shape_holder;
        ball_shape_holder.setRadius(radius);
        ball_shape_holder.setPosition(x2,y2);
        ball_shape_holder.setFillColor(color);
        ball_shape_holder.setOrigin(radius,radius);
        window.draw(ball_shape_holder);

}
   
        /*    STUFF I WILL NEED
     sf::Vector2f pos;
    float circRadius;
    float trigAngle;
    sf::Color color;
    float ballRadius;
        */







    void  CyBall::update(sf::Time tt) {
        countdown = countdown - 0.04;
        if (countdown > 0) { 
            pos.x = radius * sin(0.115 * 2 * 3.1415926) + origin.x;
            pos.y = -radius * cos(0.115 * 2 * 3.1415926) + origin.y;
            return; }

   //     counter = counter + (0.5*(tt.asSeconds()))*flag;
        counter = counter + speedthing * flag;

       // std::cout << counter << "\n";
      //  if (counter>2*3.14159265){ counter = 0; }
        double scale = radius;
        double scale2 = radius;  //two scales in case you want to do ellipses.
        pos.x = scale*sin(counter) + origin.x;
        pos.y = -scale2*cos(counter) + origin.y;

        if ((counter>0.115*2*3.1415926)||(counter<-(0.115 * 2 * 3.1415926))) {
           flag = -flag;
           speedthing = speedthing + 0.0005;
        }

    };
    void  CyBall::draw(sf::RenderWindow& window) const {
        sf::CircleShape ball_shape_holder;
        ball_shape_holder.setRadius(8);
        ball_shape_holder.setPosition(pos);
        ball_shape_holder.setFillColor(sf::Color::Red);
        ball_shape_holder.setOrigin(8, 8);
       
        sf::Vertex Leftline[] =
        {
            sf::Vertex(pos),
            sf::Vertex(origin)
        };
        window.draw(Leftline, 2, sf::Lines);
        window.draw(ball_shape_holder);
    };


    CyBall::CyBall(sf::Vector2f p, double rr, double cd) {
            origin = p;
            radius = rr;
            countdown=cd;
        }

   