#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



//utlitiy functions
bool is_line(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C);


class CyBall {
public:
    int flag = 1;
    double counter = 0.115 * 2 * 3.1415926;
    double countdown = 20;
    double speedthing = 0.0115;
    sf::Vector2f pos;
    sf::Vector2f origin;
    double radius;
    void update(sf::Time delta_t);
        void draw(sf::RenderWindow & window) const;

  
        CyBall(sf::Vector2f origin, double radius, double countdown);

};
class Ball{
public:
    Ball(sf::Vector2i screen,sf::Vector2f ipos, sf::Vector2f ivel);
    void update(sf::Time delta_t, sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D);
    void draw(sf::RenderWindow& window) const; 
    sf::Vector2i screen_size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f gravity;
    sf::Color col;
    float radius;
};

//I need initial position
//I need radius of circular motion
//I need angle (basically velocity)
//I need color
//I need ball radius (probably 7)


class TrigBall {
public:
    TrigBall(float radiusX, float radiusY, float initSpeedMultiplier, sf::Vector2f position, float motionRadius);

    void update(sf::Time deltaTime,sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D);
    void draw(sf::RenderWindow& window);
    sf::Sound sound;
private:
    float x;
    float y;
    float radius;
    float speedMultiplier;
    float x2;
    float y2;
    sf::Color color;
    sf::Vector2f pos;
    float motionRadius;
  
};



