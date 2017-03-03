#include "peerdata.h"
#include <vector>

int num_players=1;
int connecthash[100];
int packethash[100];
bool sendmydata=false;
bool game_mode=false;
vector<peerdata> gamers;
int my_num;