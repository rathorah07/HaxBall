#include "Constants.h"
#include "Player.h"
#include "Ball.h"
#include "AI.h"
#include "Positions.h"
#include "global_data.h"
#include <vector>
#include "variables.h"

float top;
float bottom;
float rightp;
float leftp;
float _ratio;
float radius_w;
ball freedom;
int count_left;
int count_right;
bool goal;
AI bot;
int AInum;
int player_number;
int num_riders;
std::vector<player> players;
std::vector<Position> Positions,temp_pos;
bool firsthit_0;
bool firsthit_1;

void initialize(float _top, float _bottom, float _right, float _left, float tratio){
	top = _top;
	bottom = _bottom;
	rightp = _right;
	leftp = _left;
	_ratio = tratio;
	radius_w = 0.025;
	count_left = 0;
	count_right = 0;
	goal = false;
	firsthit_0 = true;
	firsthit_1 = true;
    //AI_side = side;
    //bot.level = level_;

}

void init_positions(){
    players.resize(3);
    Positions.resize(3);
	freedom.color[0] = 0.8;
	freedom.color[1] = 1.0;
	freedom.color[2] = 0.0;
	Positions[0].x = freedom.pos[0];
	Positions[0].y = freedom.pos[1];
	Positions[0].vx = freedom.vel[0];
	Positions[0].vy = freedom.vel[1];
	Positions[0].in_contact = freedom.in_contact;

	players[1].team = 0;
	players[2].team = 1;
	players[1].color[0] = 0.5;
	players[1].color[1] = 0.5;
	players[1].color[2] = 0.3;

	players[2].color[0] = 0.2;
	players[2].color[1] = 0.5;
	players[2].color[2] = 0.7;
    num_riders = 2;
	player_number = 2;
	for(int i = 1; i < Positions.size(); i++){
		if(players[i].team == 0){
			Positions[i].x = -0.5;
		}
		else
			Positions[i].x = 0.5;
		Positions[i].y = 0.0;
		Positions[i].vx = 0.0;
		Positions[i].vy = 0.0;
		Positions[i].dx = 0.0;
		Positions[i].dy = 1.0;
		Positions[i].in_contact = false;
		Positions[i].hit = false;
	}

}

void init_system(){

    int left = 0;
	int right = 0;
	player_number = my_num;
    if(singleplayer)
    {
        player_number = 1;
    }
    num_riders = gamers.size();
	cout << "Num_Riders "  << num_riders << endl;
	players.resize(num_riders + 1);
	Positions.resize(num_riders + 1);
    temp_pos.resize(num_riders+1);
	freedom.color[0] = 0.8;
	freedom.color[1] = 1.0;
	freedom.color[2] = 0.0;
    Positions[0].x = freedom.pos[0];  //0
	Positions[0].y = freedom.pos[1];
	Positions[0].vx = freedom.vel[0];
	Positions[0].vy = freedom.vel[1];
    Positions[0].dx = 0;
    Positions[0].dy = 0;
    Positions[0].hit = false;
	Positions[0].in_contact = freedom.in_contact;
	for(int i = 1; i < Positions.size(); i++){
		players[i].team = gamers[i - 1].peerteam;
		if(players[i].team == 0){
			players[i].pos[0] = leftp/2;
			players[i].pos[1] = -0.1 + 0.2*left;
			players[i].color[0] = 0.2 + 0.2*left;
			players[i].color[1] = 0.0;
			players[i].color[2] = 0.0;
			left++;
            cout<<"left"<<left<<endl;
		}
        else if(players[i].team == 1){
			players[i].pos[0] = rightp/2;
			players[i].pos[1] = -0.1 + 0.2*right;
			players[i].color[0] = 0.0;
			players[i].color[1] = 0.0;
			players[i].color[2] = 0.2 + 0.2*right;
            right++;
            cout<<"right"<<right<<endl;
		}

		Positions[i].x = players[i].pos[0];
		Positions[i].y = players[i].pos[1];
		Positions[i].vx = players[i].vel[0];
		Positions[i].vy = players[i].vel[1];
        Positions[i].dx = 0;
        Positions[i].dy = 0;
		Positions[i].in_contact = players[i].in_contact;
		Positions[i].hit = players[i].hit;
	}
}

/*
void init_system(int number){
	player_number = number;
	num_players = Positions.size() - 1;
	freedom.color[0] = Positions[0].color[0];
	freedom.color[1] = Positions[0].color[1];
	freedom.color[2] = Positions[0].color[2];
	for(int i = 1; i < Positions.size(); i++){
		players[i].pos[0] = Positions[i].x;
		players[i].pos[1] = Positions[i].y;
		players[i].color[0] = Positions[i].color[0];
		players[i].color[1] = Positions[i].color[1];
		players[i].color[2] = Positions[i].color[2];
		players[i].team = Positions[i].team;
	}
}

void init_ball(){
	freedom.color[0] = 0.8;
	freedom.color[1] = 1.0;
	freedom.color[2] = 0.0;
	freedom.vel[0] = 0.0015;
}
*/
