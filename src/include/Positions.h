#ifndef POSITIONS_H
#define POSITIONS_H

struct Position{
	float x;
	float y;
	float vx;
	float vy;
	bool in_contact;
	bool hit;
	float dx;
	float dy;
};

#endif
