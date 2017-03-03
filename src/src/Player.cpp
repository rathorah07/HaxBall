// need to initialize unit vecttors globally in the main loop with the names "unit_x" and "unit_y" for x and y directions respectively
// set maximum for player speed in the main with the name "speed_max", maximum intensity as "intensity_max"
// need to check conditions for limiting the center of the player within boundaries of the stadium
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "Constants.h"

using namespace std;

float min(float x, float y){
	if (x < y){
		return x;
	}

	else
		return y;
}

float max(float x, float y){
	if (x > y)
		return x;
	else 
		return y;
}

player::player(){
	pos[0] = 0; pos[1] = 0;
	vel[0] = 0; vel[1] = 0;
	inten[0] = 0; inten[0] = 0;
    radius = 0.08;
    color[0] = 0;color[1] = 0;color[2] = 0;

	speed = 0;
    intensity = 0.05;
	hit = false;
	in_contact = false;
	team = 0;
	// parameters need to be initialized properly
}

player::player(float * position, float * velocity, float r, float input_color[3]){
	//parameters need to be initialized appropriately
	pos[0] = position[0];
	pos[1] = position[1];
	vel[0] = velocity[0];
	vel[1] = velocity[1];
	inten[0] = 0; inten[1] = 0;
	radius = r;
	color[0] = input_color[0];
	color[1] = input_color[1];
	color[2] = input_color[2];

	speed = 0;
    intensity = 0.5;
	hit = false;
	in_contact = false;
	team = 0;
}

void player::assign_direction(Vector direct){
    delete direction._vector;
    direction._vector = new float[2];
	if(direct._vector[0] == direct._vector[0])
		direction._vector[0] = direct._vector[0];
	if(direct._vector[1] == direct._vector[1])
		direction._vector[1] = direct._vector[1];
}

void player::start_player(){
	Vector unit_x(1.0, 0.0);
	Vector unit_y(0.0, 1.0);
    speed = 0.01;
	vel[0] = speed*(direction.scalar_product(unit_x));
	vel[1] = speed*(direction.scalar_product(unit_y));
}

void player::stop_player(){
	speed = 0;
	vel[0] = 0;
	vel[1] = 0;
}
/*
void player::move_player(float x, float y, float r, ball & freedom){

	float temp_x = pos[0];
	float temp_y = pos[1];

	pos[0] = pos[0] + vel[0];
	pos[1] = pos[1] + vel[1];


	
}
*/
