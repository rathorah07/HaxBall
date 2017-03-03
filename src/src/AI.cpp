#include "AI.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Ball.h"
#include "Interaction.h"
#include "Collisions.h"
#include "Detect_Goal.h"
#include "States.h"
#include "Constants.h"

using namespace std;

struct BC{
	int bound1;
	int bound2;
};

BC easy;
BC medium;
BC hard;

void initialize_level(){
	easy.bound1 = 30;
	easy.bound2 = 50;

	medium.bound1 = 10;
	medium.bound2 = 40;

	hard.bound1 = 15;
	hard.bound2 = 30;
}

bool critical(int level, player & victory, ball & freedom){
	switch(level){
	case 1 :
	{
		if((victory.team == 0 && freedom.vel[0] > 0) || (victory.team == 1 && freedom.vel[0] < 0)){
			if((victory.team == 0 && freedom.pos[0] <= 0.65 * leftp) || (victory.team == 1 && freedom.pos[0] >= 0.65 * rightp))
				return true;
			else
				return false;
		}
		else
			return false;
	}

	case 2 :
	{
		if((victory.team == 0 && freedom.vel[0] > 0) || (victory.team == 1 && freedom.vel[0] < 0)){
			if((victory.team == 0 && freedom.pos[0] <= 0.60 * leftp) || (victory.team == 1 && freedom.pos[0] >= 0.60 * rightp))
				return true;
			else
				return false;
		}
		else
			return false;
	}

	case 3 :
	{
		if((victory.team == 0 && freedom.vel[0] > 0) || (victory.team == 1 && freedom.vel[0] < 0)){
			if((victory.team == 0 && freedom.pos[0] <= 0.50 * leftp) || (victory.team == 1 && freedom.pos[0] >= 0.50 * rightp))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	}

}

bool check_hit(player & victory, ball & freedom){
	Vector unit_direction_1;
	Vector unit_direction_2;
	if(victory.team == 0){
		Vector direction_1(leftp - freedom.pos[0], (top/_ratio) - freedom.pos[1]);
		Vector direction_2(leftp - freedom.pos[0], (bottom/_ratio) - freedom.pos[1]);
		Vector unit_direction_1 = direction_1.unit_vector();
		Vector unit_direction_2 = direction_2.unit_vector();
	}
	else{
		Vector direction_1(rightp - freedom.pos[0], (top/_ratio) - freedom.pos[1]);
		Vector direction_2(rightp - freedom.pos[0], (bottom/_ratio) - freedom.pos[1]);
		Vector unit_direction_1 = direction_1.unit_vector();
		Vector unit_direction_2 = direction_2.unit_vector();
	}
	Vector target_cosines(freedom.pos[0] - victory.pos[0], freedom.pos[1] - victory.pos[1]);
	Vector target = target_cosines.unit_vector();

	if((unit_direction_1.scalar_product(target) > 0) && (unit_direction_2.scalar_product(target) > 0)){
		return false;
	}

	else
		return true;
}

AI::AI(){
	first_contact = false;
	contact = false;

	level = 3;
	counter = 241;
	is_2 = false;
	is_3 = false;
	initialize_level();
}

AI::AI(int level_){
	first_contact = false;
	contact = false;

	level = level_;
	counter = 241;
	is_2 = false;
	is_3 = false;
	initialize_level();
}

//strategy1 : bot will move about randomly in the field
//strategy2 : bot will block the path of rider
//strategy3 : bot will align itself in the direction such that a hit will cause it to move into the goal
//strategy4 : bot will prevent the ball from entering into the goal

void AI::strategy_1(player & victory, ball & freedom){
    //cout << "strategy 1 " << endl;
	Vector attack(0.1*(rand()%10), 0.1*(rand()%10));
	Vector move = attack.unit_vector();
	victory.assign_direction(move);
	victory.start_player();
	counter++;
	is_2 = false;
	is_3 = false;
}

void AI::strategy_2(player & victory, ball & freedom){
    //cout << "strategy 2 " << endl;
	int blow = num_riders;
	float temp;
	float min = 100.0;
	for(int i = 1; i < num_riders; i++){
		if(players[i].team != victory.team){
			temp = distance(players[i], freedom);
			if(temp < min){
				min = temp;
				blow = i;
			}
		}
	}

	Vector victory_pos(victory.pos[0], victory.pos[1]);
	Vector rider_pos(players[blow].pos[0], players[blow].pos[1]);
	Vector freedom_pos(freedom.pos[0], freedom.pos[1]);
	Vector path = freedom_pos.subtraction(rider_pos);
	Vector army = path.scalar_multiplication(0.5);
	Vector target = rider_pos.addition(army);
	Vector attack = target.subtraction(victory_pos);
	Vector move = attack.unit_vector();
	//cout << "move_0 : " << move._vector[0] << " move_1 : " << move._vector[1] << endl;
	victory.assign_direction(move);
	victory.start_player();

	if(check_hit(victory, freedom)){
		hit_ball(victory, freedom);
	}

	counter++;
	is_2 = true;
	is_3 = false;
}

void AI::strategy_3(player & victory, ball & freedom){
    //cout << "strategy 3 " << endl;
	// think about how to calculate a direction to hit the ball into the goal
	if((victory.team == 0 && (freedom.pos[0] - victory.pos[0]) > 0) || (victory.team == 1 && (freedom.pos[0] - victory.pos[0]) < 0)){
        //cout << "shifted to strategy 2 " << endl;
		strategy_2(victory, freedom);
	}
	else{
	 	Vector victory_pos(victory.pos[0], victory.pos[1]);
		Vector freedom_pos(freedom.pos[0], freedom.pos[1]);
		Vector ball_direction;
		if(victory.team == 0){
			ball_direction._vector[0] = rightp - freedom.pos[0];
			ball_direction._vector[1] = (-1) * freedom.pos[1];
		}
		else{
			ball_direction._vector[0] = leftp - freedom.pos[0];
			ball_direction._vector[1] = (-1) * freedom.pos[1];
		}
	Vector unit_direction = ball_direction.unit_vector();
	Vector army = unit_direction.scalar_multiplication(freedom.radius + 2 * victory.radius);
	Vector target = freedom_pos.addition(army);
	Vector attack = target.subtraction(victory_pos);
	Vector move = attack.unit_vector();

	victory.assign_direction(move);
	victory.start_player();

	if(check_hit(victory, freedom)){
		hit_ball(victory, freedom);
	}

	counter++;
	is_2 = false;
	is_3 = true;
	}
}

//This strategy blocks the path of the ball if it crosses a certain vertical line of reference
void AI::strategy_4(player & victory, ball & freedom){
    //cout << "strategy 4 " << endl;
	if(check_contact(victory, freedom) && contact_wall(freedom)){
		strategy_6(victory, freedom);
	}

	else{
		Vector position_ball(freedom.pos[0], freedom.pos[1]);
		Vector position_bot(victory.pos[0], victory.pos[1]);
		Vector ball_velocity(freedom.vel[0], freedom.vel[1]);
		Vector unit_direction = ball_velocity.unit_vector();
		Vector army = unit_direction.scalar_multiplication(freedom.radius + victory.radius);
		Vector target = position_ball.addition(army);
		Vector attack = target.subtraction(position_bot);
		Vector move = attack.unit_vector();
		counter++;
		victory.assign_direction(move);
		victory.start_player();
		is_2 = false;
		is_3 = false;
	}
}

//This strategy moves the bot towards the ball
void AI::strategy_5(player & victory, ball & freedom){
    //cout << "strategy 5 " << endl;
	first_contact = check_contact(victory, freedom);
	Vector attack(freedom.pos[0] - victory.pos[0], freedom.pos[1] - victory.pos[1]);
	Vector move = attack.unit_vector();
	victory.assign_direction(move);
	victory.start_player();
	is_2 = false;
	is_3 = false;
	counter++;

	if(counter > 480 && !first_contact){
		first_contact = true;
		//counter = 0;
	}
}

//This strategy moves the bot away from the ball
void AI::strategy_6(player & victory, ball & freedom){
    //cout << "strategy 6 " << endl;
	Vector attack(victory.pos[0] - freedom.pos[0], victory.pos[1] - freedom.pos[1]);
	Vector move = attack.unit_vector();
	victory.assign_direction(move);
	victory.start_player();
	is_2 = false;
	is_3 = false;
	counter=1;
}

void AI::move_bot(player & victory, ball & freedom){
	int selection = 0;
	victory.stop_player();
	bool is_hit = false;
	for(int i = 1; i < num_riders; i++){
		if(players[i].team != victory.team){
			if(players[i].hit){
				is_hit = true;
				break;
			}
		}
	}
	if((is_hit && !goal) || critical(level, victory, freedom)){
		strategy_4(victory, freedom);
	}

	else if(!first_contact){
		strategy_5(victory, freedom);
	}

	else if(goal){
        //cout << "Attack after goal..." << endl;
		Vector attack(-victory.pos[0], -victory.pos[1]);
		Vector move = attack.unit_vector();
		victory.assign_direction(move);
		victory.start_player();
		counter = 0;
		is_2 = false;
		is_3 = false;
		first_contact = check_contact(victory, freedom);
		counter = 0;
	}

	else{
		//randomly choose a strategy from the given list
		selection = rand()%100;
		switch(level){
			case 1 :
			{
				victory.stop_player();
				if(counter > 120){
				counter = 0;
				if(selection < easy.bound1){
					strategy_1(victory, freedom);
					//cout << "strategy 1" << endl;
				}

				else if(selection >= easy.bound1 && selection < easy.bound2){
					strategy_2(victory, freedom);
					//cout << "strategy 2" << endl;
				}

				else{
					////cout << "navi strategy" << endl;
					strategy_3(victory, freedom);
					//cout << "strategy 3" << endl;
				}
				}

				else{
					if(is_2){
						victory.start_player();
					}

					else if(is_3){
						victory.start_player();
					}

					else{
						//cout << "purani strategy..." << endl;
						victory.start_player();
						counter++;
					}
				}
			}

			case 2 :
			{
				victory.stop_player();
				if(counter > 120){
				counter = 0;
				if(selection < medium.bound1){
					strategy_1(victory, freedom);
				}

				else if(selection >= medium.bound1 && selection < medium.bound2){
					strategy_2(victory, freedom);
				}

				else{
					strategy_3(victory, freedom);
				}
				}

				else{
					if(is_2){
						victory.start_player();
					}

					else if(is_3){
						victory.start_player();
					}

					else{
						victory.start_player();
						counter++;
					}
				}
			}

			case 3 :
			{
				// need to add conditions on the time frame to make more harder
				victory.stop_player();
				if(counter > 60){
				counter = 0;
				if(selection < hard.bound1){
					strategy_1(victory, freedom);
				}

				else if(selection >= hard.bound1 && selection < hard.bound2){
					strategy_2(victory, freedom);
				}

				else{
					strategy_3(victory, freedom);
				}
				}

				else{
					if(is_2){
						strategy_2(victory, freedom);
					}

					else if(is_3){
						strategy_3(victory, freedom);
					}

					else{
						victory.start_player();
						counter++;
					}
				}
			}
		}

	}
}
