#ifndef READPACKET_H
#define READPACKET_H

#include <iostream>
#include <vector>
#include <string>
#include "helperfunc.h"
#include "variables.h"
#include "Positions.h"

struct packet1_data{

	string ip;
	string nickname;
	int port;
};

struct goal_count{
    int leftvalue;
    int rightvalue;
};

packet1_data readpeer_Firstpacket(string input);

vector<peerdata> readhost_firstpacket(string input);

string readpacket_message(string input);

goal_count readpacket_goal(string input);

vector<peerdata> readpacket_dragdrop(string input);

/*vector<Position> readpacket_gamestate(string input); */

Position readpacket_gamestate(string input,int &author);

Position readpacket_ballpos(string input);

int readpacket_disconnect(string input);


/*vector<Position> readpacket_gamestate(string input,string &author); */
#endif // READPACKET_H
