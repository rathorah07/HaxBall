#ifndef GAMESTATE_
#define GAMESTATE_

struct player_info
{
	float x;
	float y;
	float vx;
	float vy;
};

class Gamestate
{
	int players;
public:
	player_info * players_list;
	Gamestate(int);
	~Gamestate();
	
};
#endif

