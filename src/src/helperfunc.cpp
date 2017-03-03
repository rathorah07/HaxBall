#include "helperfunc.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "variables.h"
#include "global_data.h"
using namespace std;

string int_to_string(int n)
{
    string out = to_string(n);
    return out;
}


int string_to_int(string s)
{
    int out = 0 ;

    if(s[0] == '-')
    {
        for(int i=1;i<s.length();i++)
        {
            out = out*10 + s[i] - '0';
        }

        return -out;
    }

    else
    {
        for(int i=0;i<s.length();i++)
        {
            out = out*10 + s[i] - '0';
        }

        return out;
    }

}


string float_to_string(float input)
{
    string out =to_string(input);
}


float string_to_float(string input)
{
    float intpart = 0.0;
    float decpart = 0.0;

    bool flag =false;


    if(input[0] == '-')
    {


        for(int i=1;i<input.length();i++)
        {
            if(input[i] == '.')
                break;
            else
                intpart = intpart*10 + input[i] - '0';
        }

        for(int i=input.length()-1 ;i>=0;i--)
        {
            if(input[i] == '.')
                break;
            else
                decpart = decpart/10 + ((input[i] - '0')*1.0)/10;
        }

        return -(intpart + decpart);



    }

    for(int i=0;i<input.length();i++)
    {
        if(input[i] == '.')
            break;
        else
            intpart = intpart*10 + input[i] - '0';
    }

    for(int i=input.length()-1 ;i>=0;i--)
    {
        if(input[i] == '.')
            break;
        else
            decpart = decpart/10 + ((input[i] - '0')*1.0)/10;
    }

    return intpart + decpart;
}

int find_data(int startpos , string data_stream ,string &req_data)
{
    req_data ="\0";

    for(int i =startpos+1;i<data_stream.length();i++)
    {
        if(data_stream[i] == '*')
            return i;
        req_data += data_stream[i];
    }
}


vector<string> make_nick(vector<string>neutral,vector<string>TeamA,vector<string>TeamB)
{
    vector<string> out;

    for(int i=0;i<neutral.size();i++)
    {
        out.push_back(neutral[i]);
    }

    out.push_back("+");

    for(int i=0;i<TeamA.size();i++)
    {
        out.push_back(TeamA[i]);
    }

    out.push_back("+");

    for(int i=0;i<TeamB.size();i++)
    {
        out.push_back(TeamB[i]);
    }

    return out;

}

void copy_vec(vector<string>input,vector<QString>&output)
{
    output.clear();
    for(int i=0;i<input.size();i++)
    {
       output.push_back(QString::fromStdString(input[i]));
    }
}

int find_peerpos(string name){

    for(int i=0;i<gamers.size();i++)
    {
        if(gamers[i].peername == name)
            return i;
    }

    return -1;
}

int findip_pos(string ipadd)
{
    for(int i=0;i<gamers.size();i++)
    {
        if(gamers[i].peerip == ipadd)
            return i+1;
    }

    return -1;
}



