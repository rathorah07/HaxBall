#include "Gamestate.h"

Gamestate::Gamestate(int num)
{
	players = num;
	players_list = new player_info[players];
}
