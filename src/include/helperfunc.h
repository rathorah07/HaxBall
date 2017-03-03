#ifndef HELPERFUNC_H
#define HELPERFUNC_H

#include <vector>
#include <iostream>
#include <string>
#include "Gamestate.h"
#include <QtCore>

using namespace std;

string int_to_string(int);
int string_to_int(string);

string float_to_string(float);
float string_to_float(string);

int find_data(int , string,string&);

vector<string> make_nick(vector<string>neutral,vector<string>TeamA,vector<string>TeamB);

void copy_vec(vector<string>A,vector<QString>& B);

int find_peerpos(string name);

int findip_pos(string ipadd);

#endif // HELPERFUNC_H
