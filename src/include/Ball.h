#ifndef BALL_H
#define BALL_H

#include "Vector.h"

class ball{
	public :
		float pos[2];
		float vel[2]; 
		float radius; 
		float color[3];
		bool in_contact;

	public :
		ball();
		ball(float * position, float * velocity, float r, float input_color[3]);
		void check_wall();
		//void move_ball(float x, float y, float r, float vel_x, float vel_y);
};

#endif