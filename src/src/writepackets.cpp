#include "writepackets.h"
#include "variables.h"

#include <iostream>
#include <vector>
#include <string>
#include "helperfunc.h"
#include "variables.h"
#include "global_data.h"
#include "Positions.h"

string writepeer_Firstpacket(string playername,string ip,int port)
{
    string out ="1";    // type 1 packet peer->host   // information : peer nickname
    out += '*';
    out += playername + '*' + ip + '*' + to_string(port) + '*';

    return out;
}


string writehost_firstpacket(vector<peerdata> gamers)
{
    string out ="2";    // type 2 packet host->peer  // information : peer playernumber, number of total players ,their ip ,port and names

    out += '*' + to_string(gamers.size());
    for(int i=0;i<gamers.size();i++)
    {
        out+= '*' + gamers[i].peername + '*' + to_string(gamers[i].peerteam)+ '*' + gamers[i].peerip + '*' + to_string(gamers[i].peerport) + '*' + to_string(gamers[i].peernum);
    }

    out += '*';

    return out;
}


string writepacket_message(string input)
{
    string out = "3";
    out += '*'+ input +'*';
    return out;
}

string writepacket_hostdrag(vector<peerdata> gamers)
{
    string out ="4";

    out += '*' + to_string(gamers.size());
    for(int i=0;i<gamers.size();i++)
    {
        out+= '*' + gamers[i].peername + '*' + to_string(gamers[i].peerteam)+ '*' + gamers[i].peerip + '*' + to_string(gamers[i].peerport) + '*' + to_string(gamers[i].peernum);
    }

    out += '*';

    return out;
}


string writepacket_startgame()   // host->peer game starting
{
    string out="5";

    return out;
}


string writepacket_goal(int left,int right)
{
    string out = "6";
    out += '*' + to_string(left) + '*' +to_string(right) +'*';
    return out;
}

/*string writepacket_gamestate(vector<Position> input)
{
    string out ="7";
    out+= '*' + to_string(input.size()) ;
    for(int i=0;i<input.size();i++)
    {
        out += '*' + to_string(input[i].x) + '*' + to_string(input[i].y) + '*' + to_string(input[i].vx)
                 + '*' + to_string(input[i].vy) + '*' + to_string(input[i].in_contact) + '*' + to_string(input[i].hit)
                + '*' + to_string(input[i].dx) + '*' + to_string(input[i].dy);
    }
    out+= '*';
    return out;
} */


string writepacket_endgame()
{
    string out ="8";
    return out;
}

string writepacket_random()
{
    string out = "9";
    out+= "*random_packet*";
    return out;
}

string writepacket_gamestate(vector<Position> input,int pos=my_num)
{
    int i  = pos;
    string out ="7";
    out+= '*' +to_string(i);
        out += '*' + to_string(input[i].x) + '*' + to_string(input[i].y) + '*' + to_string(input[i].vx)
                 + '*' + to_string(input[i].vy) + '*' + to_string(input[i].in_contact) + '*' + to_string(input[i].hit)
                + '*' + to_string(input[i].dx) + '*' + to_string(input[i].dy);
    out+= '*';
    return out;
}


string writepacket_ballpos(vector<Position> input)
{
    int i  = 0;
    string out ="@";
        out += '*' + to_string(input[i].x) + '*' + to_string(input[i].y) + '*' + to_string(input[i].vx)
                 + '*' + to_string(input[i].vy) + '*' + to_string(input[i].in_contact) + '*' + to_string(input[i].hit)
                + '*' + to_string(input[i].dx) + '*' + to_string(input[i].dy);
    out+= '*';
    return out;
}

string writepacket_disconnect(int input)
{
    string out = "#";
    out += '*' + to_string(input) + '*';
    return out;
}

