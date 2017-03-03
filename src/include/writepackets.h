#ifndef WRITEPACKETS_H
#define WRITEPACKETS_H

#include <iostream>
#include <vector>
#include <string>
#include "helperfunc.h"
#include "variables.h"
#include "Positions.h"

string writepeer_Firstpacket(string playername,string ip,int port);

string writehost_firstpacket(vector<peerdata> gamers);

string writepacket_startgame();

string writepacket_goal(int left,int right);

string writepacket_endgame();

string writepacket_random();

string writepacket_gamestate(vector<Position> input,int pos);

string writepacket_message(string input);

string writepacket_hostdrag(vector<peerdata> gamers);

string writepacket_ballpos(vector<Position> input);

string writepacket_disconnect(int input);



#endif // WRITEPACKETS_H
