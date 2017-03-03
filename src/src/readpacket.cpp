#include "readpacket.h"
#include <iostream>
#include <vector>
#include <string>
#include "helperfunc.h"
#include "variables.h"
#include "peerdata.h"
#include "Positions.h"

packet1_data readpeer_Firstpacket(string input)   // read packet 1,returns nickname
{   
    packet1_data out;
    string packetdata ,ip ,temp;
    int port =0;

    int flag =0;

    for(int i=0;i<input.length();i++)
    {

        switch(flag)
        {
            case 1:
            if(input[i] != '*')
            {
                packetdata += input[i];
            }
            break;

            case 2:
            if(input[i] != '*')
            {
                ip += input[i];
            }
            break;

            case 3:
            if(input[i] != '*')
            {
                temp += input[i];
            }
            break;

            default:
                break;
        }


        if(input[i] == '*')
            flag++;
    }

    port = string_to_int(temp);
    out.port =port;
    out.nickname = packetdata;
    out.ip = ip;
    return out;
}


vector<peerdata> readhost_firstpacket(string input)   // read packet 2 and load it into global vectors
{   
    vector<peerdata> out;
    peerdata temp;
    int num;
    int pos = 0; string tempdata;
    pos =find_data(pos,input,tempdata);
    num = string_to_int(tempdata);

    for(int i=0;i<num;i++)
    {
        pos = find_data(pos,input,tempdata);
        temp.peername = tempdata;

        pos = find_data(pos,input,tempdata);
        temp.peerteam = string_to_int(tempdata);

        pos = find_data(pos,input,tempdata);
        temp.peerip = tempdata;

        pos = find_data(pos,input,tempdata);
        temp.peerport = string_to_int(tempdata);

        pos = find_data(pos,input,tempdata);
        temp.peernum = string_to_int(tempdata);

        out.push_back(temp);

    }

    return out;

}

string readpacket_message(string input)
{
    int pos =0;
    string temp;
    pos = find_data(pos,input,temp);
    return temp;
}

goal_count readpacket_goal(string input)
{
    int pos =0;
    string tempdata;
    goal_count out;

    pos = find_data(pos,input,tempdata);
    out.leftvalue = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.rightvalue = string_to_int(tempdata);

    return out;

}

vector<peerdata> readpacket_dragdrop(string input)
{
    return readhost_firstpacket(input);
}


Position readpacket_gamestate(string input,int &author)
{
    Position out;
    int pos=0;
    string tempdata;
    pos = find_data(pos,input,tempdata);
    author = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.x = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.y = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.vx = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.vy = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.in_contact = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.hit = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.dx = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.dy = string_to_float(tempdata);

    return out;

}


Position readpacket_ballpos(string input)
{

    Position out;
    int pos=0;
    string tempdata;

    pos = find_data(pos,input,tempdata);
    out.x = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.y = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.vx = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.vy = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.in_contact = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.hit = string_to_int(tempdata);

    pos = find_data(pos,input,tempdata);
    out.dx = string_to_float(tempdata);

    pos = find_data(pos,input,tempdata);
    out.dy = string_to_float(tempdata);

    return out;

}

int readpacket_disconnect(string input)
{
    string temp;
    int out;
    int pos =0;
    pos =find_data(pos,input,temp);
    out = string_to_int(temp);
    return out;
}


/*vector<Position> readpacket_gamestate(string input)
{
    vector<Position> out;
    int count,pos=0;
    string tempdata;

    pos = find_data(pos,input,tempdata);
    count = string_to_int(tempdata);

    for(int i =0 ;i<count;i++)
    {
        pos = find_data(pos,input,tempdata);
        out[i].x = string_to_float(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].y = string_to_float(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].vx = string_to_float(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].vy = string_to_float(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].in_contact = string_to_int(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].hit = string_to_int(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].dx = string_to_float(tempdata);

        pos = find_data(pos,input,tempdata);
        out[i].dy = string_to_float(tempdata);
    }

} */

