#ifndef VARIABLES
#define VARIABLES
#include <iostream>
#include <QString>
#include <vector>
#include <string>
#include "mysignal.h"
#include "gamelobby.h"
#include "peerdata.h"
using namespace std;

extern vector <QString> vecmessages;
extern string my_message;
extern gamelobby *main_object;
extern bool disco;
extern int mincounter;
extern bool singleplayer;
extern int maxgoal;
extern bool mess;
extern int myportnum;
extern bool Aipresent;
extern int Ai_team;
extern int hostportnum;
extern string hostip,myip;
extern int counter;
extern bool playing;
extern int myplayernum;
extern bool name_set;
extern bool dragged;
extern bool state_connected;
extern float myratio;
extern MySignal game_signal;
extern vector<string> iplist;
extern vector<int>portlist,player_numlist;
extern int player_num,num_elem;
extern string playername;
extern bool host ,up1,down1,left1,right1,hit1;
extern vector <QString> TeamA_vector;
extern vector <QString> TeamB_vector;
extern vector <QString> NeutralTeam_vector;
extern void initalize(QString);




#endif // VARIABLES

