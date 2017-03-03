// need to define global paramters containing the width and the height of the stadium to be accessed by the system
// need to check conditions for collision with the boundaries of the stadium
// global variables in the main file for the top, bottom, right and left of the stadium

#include "Ball.h"
#include "Player.h"
#include "Constants.h"
#include "variables.h"

ball::ball(){
	pos[0] = 0; pos[1] = 0;
	vel[0] = 0; vel[1] = 0;
    radius = 0.06;
    color[0] = 0;color[1] = 0;color[2] = 0;
	in_contact = false;
}

ball::ball(float * position, float * velocity, float r, float input_color[3]){
	pos[0] = position[0];
	pos[1] = position[1];
	vel[0] = velocity[0];
	vel[1] = velocity[1];
	radius = r;
	color[0] = input_color[0];
	color[1] = input_color[1];
	color[2] = input_color[2];
	in_contact = false;

}

void ball::check_wall(){

    bool collide = false;

    if(pos[0] + radius > rightp || pos[0] - radius < leftp)
        collide = true;

    if(pos[1] + radius > top || pos[1] -radius < bottom )
        collide = true;

    if ((pos[1] + radius >= top-0.0005))
	{
        if(vel[1] > 0)
        vel[1] = -vel[1];

	}

    else if((pos[1] - radius <= bottom + 0.0005))
    {
        if(vel[1] < 0)
            vel[1] = - vel[1];
    }

    if(((pos[0] + radius >= rightp -0.0005) && ((pos[1] + radius >= (top/_ratio)) || (pos[1] - radius <= ((-1)*(top/_ratio))))))
    {
        if(vel[0] > 0)
		vel[0] = -vel[0];

    }

    else if(((pos[0] - radius <= leftp + 0.0005) && ((pos[1] + radius >= (top/_ratio)) || (pos[1] - radius <= ((-1)*(top/_ratio))))))
    {
        if(vel[0] < 0)
            vel[0] = -vel[0];
    }

    if(!collide)
    {
        if(vel[0] > 0)
            vel[0] = vel[0] - 0.0002;

        else if(vel[0] < 0)
            vel[0] = vel[0] + 0.0002;

        if(vel[1] > 0)
            vel[1] = vel[1] - 0.0002;

        else if(vel[1] < 0)
            vel[1] = vel[1] + 0.0002;
    }

}
/*
void ball::move_ball(float x, float y, float r, player & rider){
	
	if(!moved){
		pos[0] = pos[0] + vel[0];	
		pos[1] = pos[1] + vel[1];
	}
	//vel[0] = vel[0] - 0.001;
	//vel[1] = vel[1] - 0.001;
	
	if(((pos[0] - x)*(pos[0] - x) + (pos[1] - y)*(pos[1] - y)) < (r + radius)*(r + radius)){
		pos[0] = pos[0] - vel[0];
		pos[1] = pos[1] - vel[1];
	}
	
}
*/
