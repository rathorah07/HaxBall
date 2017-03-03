#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Ball.h"
#include "Constants.h"
#include <cmath>

using namespace std;

float distance(player rider, ball freedom){
	return ((rider.pos[0] - freedom.pos[0])*(rider.pos[0] - freedom.pos[0]) + (rider.pos[1] - freedom.pos[1])*(rider.pos[1] - freedom.pos[1]));
}

bool check_contact(player &rider, ball &freedom){
	if(distance(rider, freedom) <= (rider.radius + freedom.radius)*(rider.radius + freedom.radius) + 0.0001){
		if(rider.team == 0 && !firsthit_0){
			firsthit_0 = true;
		}
		else if(rider.team == 1 && !firsthit_1){
			firsthit_1 = true;
		}
		return true;
	}

	else 
		return false;
}

bool check_contact_LT(ball & freedom){
	if((freedom.pos[0] - leftp)*(freedom.pos[0] - leftp) + (freedom.pos[1] - (top/_ratio))*(freedom.pos[1] - (top/_ratio)) <= (freedom.radius + radius_w)*(freedom.radius + radius_w)) 
		return true;
	else 
		return false;
}

bool check_contact_RT(ball & freedom){
	if((freedom.pos[0] - rightp)*(freedom.pos[0] - rightp) + (freedom.pos[1] - (top/_ratio))*(freedom.pos[1] - (top/_ratio)) <= (freedom.radius + radius_w)*(freedom.radius + radius_w)) 
		return true;
	else 
		return false;	
}

bool check_contact_LB(ball & freedom){
	if((freedom.pos[0] - leftp)*(freedom.pos[0] - leftp) + (freedom.pos[1] + (top/_ratio))*(freedom.pos[1] + (top/_ratio)) <= (freedom.radius + radius_w)*(freedom.radius + radius_w)) 
		return true;
	else 
		return false;
}

bool check_contact_RB(ball & freedom){
	if((freedom.pos[0] - rightp)*(freedom.pos[0] - rightp) + (freedom.pos[1] + (top/_ratio))*(freedom.pos[1] + (top/_ratio)) <= (freedom.radius + radius_w)*(freedom.radius + radius_w)) 
		return true;
	else 
		return false;
}

void hit_ball(player &rider, ball &freedom){
	if (check_contact(rider, freedom)){
		rider.hit = true;
	}

}

bool check_contact_player(player & rider, player & enemy){
	if(((rider.pos[0] - enemy.pos[0])*(rider.pos[0] - enemy.pos[0]) + (rider.pos[1] - enemy.pos[1])*(rider.pos[1] - enemy.pos[1])) <= (rider.radius + enemy.radius)*(rider.radius + enemy.radius)){
		return true;
	}

	else
		return false;
}
