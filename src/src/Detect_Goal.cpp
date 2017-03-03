#include <iostream>
#include <cstdlib>
#include "Detect_Goal.h"
#include "Player.h"
#include "Ball.h"
#include <vector>
#include "Constants.h"
#include "variables.h"
#include "mysignal.h"

using namespace std;

void detect_goal(){
	int left = 0;
	int right = 0;
    if(freedom.pos[0] - freedom.radius >= rightp){
		if((freedom.pos[1] + freedom.radius <= (top/_ratio)) && (freedom.pos[1] - freedom.radius >= (-(top/_ratio)))){
			count_right++;
            emit game_signal.goal_score(1);
			//cout << "Right side goal " << count_right << endl;
			//cout << freedom.pos[0] << " " << freedom.pos[1] << endl;
			freedom.pos[0] = 0.0;
			freedom.pos[1] = 0.0;
			freedom.vel[0] = 0.0;
			freedom.vel[1] = 0.0;
			goal = true;

			for(int i = 1; i < players.size(); i++){
				if(players[i].team == 0){
					players[i].pos[0] = leftp/2; 
					players[i].pos[1] = -0.1 + 0.2*left;
					left++;
				}

				else{
					players[i].pos[0] = rightp/2; 
					players[i].pos[1] = -0.1 + 0.2*right;
					right++;	
				}
				players[i].stop_player();
			}
			firsthit_1 = false;
			//exit(0);
		}
	}

    else if(freedom.pos[0] + freedom.radius <= leftp){
		if((freedom.pos[1] + freedom.radius <= (top/_ratio)) && (freedom.pos[1] - freedom.radius >= ((-1)*(top/_ratio)))){
			count_left++;
            emit game_signal.goal_score(2);
			//cout << "Left side goal " << count_left << endl;
			//cout << freedom.pos[0] << " " << freedom.pos[1] << endl;
			freedom.pos[0] = 0.0;
			freedom.pos[1] = 0.0;
			freedom.vel[0] = 0.0;
			freedom.vel[1] = 0.0;
            goal = true;

            /*
			rider1.pos[0] = 0.5; rider1.pos[1] = 0.0;
			rider2.pos[0] = -0.5; rider2.pos[1] = 0.0;
			rider1.stop_player();
			rider2.stop_player();
			move_1 = false;
			*/
			for(int i = 1; i < players.size(); i++){
				if(players[i].team == 0){
					players[i].pos[0] = leftp/2; 
					players[i].pos[1] = -0.1 + 0.2*left;
					left++;
				}

				else{
					players[i].pos[0] = rightp/2; 
					players[i].pos[1] = -0.1 + 0.2*right;
					right++;	
				}
				players[i].stop_player();
			}
			firsthit_0 = false;
			//exit(0);
		}	
	}
}
