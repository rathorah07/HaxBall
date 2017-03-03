#include <iostream>
#include "Display.h"
#include "Vector.h"
#include "Constants.h"
#include "Player.h"
#include "Ball.h"
#include "Interaction.h"
#include "variables.h"
#include "Constants.h"
using namespace std;


void keySpecialOperations(void) {
    players[player_number].stop_player();
    if(hit1){
        hit_ball(players[player_number], freedom);
    }
    if (left1 && up1) {
        players[player_number].assign_direction(Vector(-1.0, 1.0).unit_vector());
        players[player_number].start_player();
    }


    else if (down1 && left1) {
        players[player_number].assign_direction(Vector(-1.0, -1.0).unit_vector());
        players[player_number].start_player();
    }


    else if (right1 && up1) {
        players[player_number].assign_direction(Vector(1.0, 1.0).unit_vector());
        players[player_number].start_player();
    }


    else if (right1 && down1) {
        players[player_number].assign_direction(Vector(1.0, -1.0).unit_vector());
        players[player_number].start_player();
    }
    else if (left1) {
        players[player_number].assign_direction(Vector(-1.0, 0.0));
        players[player_number].start_player();
    }

    else if (right1) {
        players[player_number].assign_direction(Vector(1.0, 0.0));
        players[player_number].start_player();
    }     

    else if (up1) {
        players[player_number].assign_direction(Vector(0.0, 1.0));
        players[player_number].start_player();


    }

    else if (down1) {
        players[player_number].assign_direction(Vector(0.0, -1.0));
        players[player_number].start_player();
    }
    else{
        
    }


}
  
