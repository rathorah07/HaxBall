#include <iostream>
#include <cstdlib>
#include "States.h"
#include "Player.h"
#include "Ball.h"
#include "Constants.h"
#include "Interaction.h"
#include "Vector.h"
#include <cmath>
#include <vector>
#include "variables.h"

using namespace std;

float absolute(float x){
	if(x >= 0)
		return x;
	else
		return (-1) * x; 
}

bool check_direction(float x, float y, player & rider){
	Vector normal(x,y);
	if(normal.scalar_product(rider.direction) > 0)
		return false;
	else
		return true;

}

bool contact_wall(ball & freedom){
	if(freedom.pos[0] + freedom.radius >= rightp || freedom.pos[0] - freedom.radius <= leftp || freedom.pos[1] + freedom.radius >= top || freedom.pos[1] - freedom.radius <= bottom){
		return true;
	}
	else 
		return false;
}

void move_system(){
	freedom.check_wall();
	Vector unit_x(1.0, 0.0);
	Vector unit_y(0.0, 1.0);

	//float min_time = time_frame;
	//float temp_time;
	//bool worked = false;
	//float approach;
	float separation;
	float temp_x;
	float temp_y;
	float length;
	/*
	for(int i = 1; i < players.size(); i++){
			Vector normal(freedom.pos[0] - players[i].pos[0], freedom.pos[1] - players[i].pos[1]);
			Vector unit_normal = normal.unit_vector();

			Vector v1(freedom.vel[0], freedom.vel[1]);
			Vector v2(players[i].vel[0], players[i].vel[1]);
	
			float v1n = v1.scalar_product(unit_normal);
			float v2n = v2.scalar_product(unit_normal);
			
			if(v1n >= 0){
				if(v2n >= 0 && (v2n - v1n > 0)){
				approach = v2n - v1n;
				separation = sqrt(distance(players[i], freedom)) - (players[i].radius + freedom.radius) - 0.01;
				temp_time = separation / approach;
				if(temp_time < 0)
				if(temp_time < min_time && temp_time > 0){
					min_time = temp_time;
					worked = true;
				}
				}
			}

			else{
				if(v2n >= 0 && ((v2n - v1n) != 0)){
				approach = v2n - v1n;
				separation = sqrt(distance(players[i], freedom)) - (players[i].radius + freedom.radius) - 0.01;
				temp_time = separation / approach;
				if(temp_time < 0)
				if(temp_time < min_time && temp_time > 0){
					min_time = temp_time;
					worked = true;
				}
				}	
				else if(v2n < 0 && (v2n - v1n) > 0){
				approach = v2n - v1n;
				separation = sqrt(distance(players[i], freedom)) - (players[i].radius + freedom.radius) - 0.01;
				temp_time = separation / approach;
				if(temp_time < 0)
				if(temp_time < min_time && temp_time > 0){
					min_time = temp_time;
					worked = true;
				}
				}
			}
	}
	if(!worked){
	freedom.pos[0] = freedom.pos[0] + (freedom.vel[0] * time_frame);
	freedom.pos[1] = freedom.pos[1] + (freedom.vel[1] * time_frame);

	for(int j = 1; j < players.size(); j++){
			temp_x = players[j].pos[0];
			temp_y = players[j].pos[1];
			players[j].pos[0] = players[j].pos[0] + players[j].vel[0] * time_frame;
			players[j].pos[1] = players[j].pos[1] + players[j].vel[1] * time_frame;
			if((players[j].team == 0 && !firsthit_1) || (players[j].team == 1 && !firsthit_0)){
				length = temp_x*temp_x + temp_y*temp_y;
				if((length <= (0.4 + players[j].radius)*(0.4 + players[j].radius)) && check_direction(temp_x, temp_y, players[j])){
					players[j].pos[0] = temp_x;
					players[j].pos[1] = temp_y;
				}
			}

			if(players[j].pos[0] - players[j].radius < -0.96)
				players[j].pos[0] = -0.96 + players[j].radius;

			if(players[j].pos[0] + players[j].radius > 0.96)
				players[j].pos[0] = 0.96 - players[j].radius;

			if(players[j].pos[1] + players[j].radius > 0.96)
				players[j].pos[1] = 0.96 - players[j].radius;

			if(players[j].pos[1] - players[j].radius < -0.96)
				players[j].pos[1] = -0.96 + players[j].radius;

			if(check_contact(players[j], freedom) && contact_wall(freedom)){
				cout << "phass gaya...." << endl << endl << endl;
				players[j].pos[0] = temp_x;
				players[j].pos[1] = temp_y;
				//exit(0);
			}
		}
	}

	else{
	freedom.pos[0] = freedom.pos[0] + (freedom.vel[0] * min_time);
	freedom.pos[1] = freedom.pos[1] + (freedom.vel[1] * min_time);

	for(int j = 0; j < players.size(); j++){
			temp_x = players[j].pos[0];
			temp_y = players[j].pos[1];
			players[j].pos[0] = players[j].pos[0] + (players[j].vel[0] * min_time);
			players[j].pos[1] = players[j].pos[1] + (players[j].vel[1] * min_time);			
			if((players[j].team == 0 && !firsthit_1) || (players[j].team == 1 && !firsthit_0)){
				length = temp_x*temp_x + temp_y*temp_y;
				if((length <= (0.4 + players[j].radius)*(0.4 + players[j].radius)) && check_direction(temp_x, temp_y, players[j])){
					players[j].pos[0] = temp_x;
					players[j].pos[1] = temp_y;
				}
			}

			if(players[j].pos[0] - players[j].radius < -0.96)
				players[j].pos[0] = -0.96 + players[j].radius;

			if(players[j].pos[0] + players[j].radius > 0.96)
				players[j].pos[0] = 0.96 - players[j].radius;

			if(players[j].pos[1] + players[j].radius > 0.96)
				players[j].pos[1] = 0.96 - players[j].radius;

			if(players[j].pos[1] - players[j].radius < -0.96)
				players[j].pos[1] = -0.96 + players[j].radius;

			if(check_contact(players[j], freedom) && contact_wall(freedom)){
				cout << "phass gaya...." << endl << endl << endl;
				players[j].pos[0] = temp_x;
				players[j].pos[1] = temp_y;
			}
	}
}
	*/
	freedom.pos[0] = freedom.pos[0] + (freedom.vel[0]);
	freedom.pos[1] = freedom.pos[1] + (freedom.vel[1]);

	for(int j = 1; j < players.size(); j++){
			temp_x = players[j].pos[0];
			temp_y = players[j].pos[1];
			players[j].pos[0] = players[j].pos[0] + players[j].vel[0];
			players[j].pos[1] = players[j].pos[1] + players[j].vel[1];
			if((players[j].team == 0 && !firsthit_1) || (players[j].team == 1 && !firsthit_0)){
				length = temp_x*temp_x + temp_y*temp_y;
				if((length <= (0.4 + players[j].radius)*(0.4 + players[j].radius)) && check_direction(temp_x, temp_y, players[j])){
					players[j].pos[0] = temp_x;
					players[j].pos[1] = temp_y;
				}
			}

            if(players[j].pos[0] - players[j].radius < -0.96*myratio)
                players[j].pos[0] = -0.96*myratio + players[j].radius;

            if(players[j].pos[0] + players[j].radius > 0.96*myratio)
                players[j].pos[0] = 0.96*myratio - players[j].radius;

			if(players[j].pos[1] + players[j].radius > 0.96)
				players[j].pos[1] = 0.96 - players[j].radius;

			if(players[j].pos[1] - players[j].radius < -0.96)
				players[j].pos[1] = -0.96 + players[j].radius;

			if(check_contact(players[j], freedom) && contact_wall(freedom)){
				cout << "phass gaya...." << endl << endl;
				players[j].pos[0] = temp_x;
				players[j].pos[1] = temp_y;
			}
		}
}
