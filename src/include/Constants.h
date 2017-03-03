#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Player.h"
#include "Ball.h"
#include "AI.h"
#include "Positions.h"
#include "global_data.h"
#include <vector>

extern float top;
extern float bottom;
extern float rightp;
extern float leftp;
extern float _ratio;
extern float radius_w;
extern ball freedom;
extern int count_left;
extern int count_right;
extern bool goal;
extern AI bot;
extern int AInum;
extern int player_number;
extern int num_riders;
extern vector<Position> temp_pos;
extern std::vector<player> players;
extern std::vector<Position> Positions;
extern bool firsthit_0;
extern bool firsthit_1;

extern void initialize(float, float, float, float, float);
extern void init_positions();
extern void init_system();

#endif
