#ifndef AI_H
#define AI_H

#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Ball.h"
#include "Interaction.h"
#include "Collisions.h"
#include "Detect_Goal.h"

class AI{
	public :
		int counter;
		bool is_2;
		bool is_3;
		int level;
		bool first_contact;
		bool contact;

	public :
		AI();
		AI(int level_);	//hardness level will decide the probabilites of different strategies
		void move_bot(player & victory, ball & freedom);
		void strategy_1(player & victory, ball & freedom);
		void strategy_2(player & victory, ball & freedom);
		void strategy_3(player & victory, ball & freedom);
		void strategy_4(player & victory, ball & freedom);
		void strategy_5(player & victory, ball & freedom);
		void strategy_6(player & victory, ball & freedom);
};

#endif
