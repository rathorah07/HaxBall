#include "variables.h"
#include <string>
#include "mysignal.h"
#include "gamelobby.h"

gamelobby *main_object;
bool host ;
int mincounter;
int maxgoal;
bool mess;
bool disco =false;
vector<QString> vecmessages;
string my_message;
bool name_set=false;
int myportnum;
bool Aipresent;
int Ai_team;
bool singleplayer = false;
int hostportnum;
string hostip,myip;
vector<peerdata> PEER;
int counter = 0 ;
int myplayernum;
bool state_connected = false;
string playername;
bool playing = true;
MySignal game_signal;
bool dragged;
float myratio =1.0;
int player_num ,num_elem;
bool up1 =false,down1 =false,left1=false,right1= false,hit1=false;
vector<string> iplist;
vector<int>portlist,player_numlist;
vector <QString> TeamA_vector;
vector <QString> TeamB_vector;
vector <QString> NeutralTeam_vector;
void initalize(string player)
{
   playername = player;
}
