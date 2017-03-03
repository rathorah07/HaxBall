#ifndef global_data_H
#define global_data_H
#include <vector>
#include "peerdata.h"
using namespace std;

extern int num_players;
extern vector<peerdata> gamers;
extern int connecthash[100];

extern int my_num;
extern int packethash[100];
extern bool sendmydata;
extern bool game_mode;
#endif
