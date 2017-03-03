#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "Player.h"
#include "Ball.h"
#include "Interaction.h"

void collision(player & rider, ball & freedom);
void check_post(ball & freedom);
void collision_wall(ball & freedom, float x, float y);
void collision_players(player & rider, player & enemy);


#endif