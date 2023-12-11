#include "utilityFunctions.h"
#include <cmath>



float angle_of_a_vector(sf::Vector2f v) {
	if (v.x < 0) {
		return 3.14159 + atan(v.y / v.x);
	}
	else if ((v.x > 0) && (v.y >= 0)) {
		return atan(v.y / v.x);
	}
	else if ((v.x > 0) && (v.y < 0)) {
		return 2 * 3.14159 + atan(v.y / v.x);
	}
	else if ((v.x == 0) && (v.y == 0)) {
		return 0;
	}
	else if ((v.x == 0) && (v.y >= 0)) {
		return 2 * 3.14159 / 4;
	}
	return 6 * 3.14159 / 4;
}
float magnitude_of_a_vector(sf::Vector2f x) {
	return pow((x.x) * (x.x) + (x.y) * (x.y), 0.5);
}




void collision_wrangler(Ball* a, Ball* b) //This function takes two balls and deals with their collision.
{

	float current_distance = (a->pos.x - b->pos.x) * (a->pos.x - b->pos.x)
		+ (a->pos.y - b->pos.y) * (a->pos.y - b->pos.y); //(This is the squared distance)

	sf::Vector2f future_pos_a = a->pos;
	sf::Vector2f future_pos_b = b->pos;

	future_pos_a = future_pos_a + (0.01f * a->vel);
	future_pos_b = future_pos_b + (0.01f * b->vel);

	float future_distance = (future_pos_a.x - future_pos_b.x) * (future_pos_a.x - future_pos_b.x)
		+ (future_pos_a.y - future_pos_b.y) * (future_pos_a.y - future_pos_b.y);

	if (future_distance > current_distance) { return; } //They are moving away from each other, so leave them be.


	sf::Vector2f vector_between_balls = b->pos - a->pos;

	//Now, we need the angle of this vector

	float angle_of_line_between_balls = angle_of_a_vector(vector_between_balls);

	//Now we want to get Ball A's velocity vector and Ball B's velocity vector and see 'how much'
	//of it is pointing in the direction of the angle_of_line_between_balls.

	float angle_of_a = angle_of_a_vector(a->vel);
	float angle_of_b = angle_of_a_vector(b->vel);

	float mag_of_a = magnitude_of_a_vector(a->vel);
	float mag_of_b = magnitude_of_a_vector(b->vel);

	sf::Vector2f rotated_vel_vector_a;
	rotated_vel_vector_a.x = mag_of_a * cos(angle_of_a - angle_of_line_between_balls);
	rotated_vel_vector_a.y = mag_of_a * sin(angle_of_a - angle_of_line_between_balls);
	sf::Vector2f rotated_vel_vector_b;
	rotated_vel_vector_b.x = mag_of_b * cos(angle_of_b - angle_of_line_between_balls);
	rotated_vel_vector_b.y = mag_of_b * sin(angle_of_b - angle_of_line_between_balls);

	rotated_vel_vector_a.x = ((a->radius - b->radius) * rotated_vel_vector_a.x + (b->radius + b->radius) * rotated_vel_vector_b.x) / (a->radius + b->radius);
	rotated_vel_vector_b.x = ((a->radius + a->radius) * rotated_vel_vector_a.x + (b->radius - a->radius) * rotated_vel_vector_b.x) / (a->radius + b->radius);

	a->vel.x = cos(angle_of_line_between_balls) * rotated_vel_vector_a.x + cos(angle_of_line_between_balls + 3.14159 / 2) * rotated_vel_vector_a.y;
	a->vel.y = sin(angle_of_line_between_balls) * rotated_vel_vector_a.x + sin(angle_of_line_between_balls + 3.14159 / 2) * rotated_vel_vector_a.y;

	b->vel.x = cos(angle_of_line_between_balls) * rotated_vel_vector_b.x + cos(angle_of_line_between_balls + 3.14159 / 2) * rotated_vel_vector_b.y;
	b->vel.y = sin(angle_of_line_between_balls) * rotated_vel_vector_b.x + sin(angle_of_line_between_balls + 3.14159 / 2) * rotated_vel_vector_b.y;
}
