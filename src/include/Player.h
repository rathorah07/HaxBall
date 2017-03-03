#ifndef PLAYER_H
#define PLAYER_H

#include "Vector.h"
#include "Ball.h"

class player{
	public :
		float pos[2];
		float vel[2];
		float inten[2];
		float radius;
		float color[3];
		float speed;
		float intensity;
		bool hit;
		bool in_contact;
		int team;
		Vector direction;

	public :
		player();
		player(float * position, float * velocity, float r, float input_color[3]);
		void assign_direction(Vector direc);
		//void move_player(float x, float y, float r, ball & freedom);
		void start_player();
		void stop_player();
};

#endif