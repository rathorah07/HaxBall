#include "peerdata.h"

peerdata::peerdata()
{
    peername = "player";
    peerip ="0.0.0.0";
    peerport= 0;
    peernum =0;
    peerteam = 3;
}

peerdata::peerdata(string name,string ip,int port,int numb)
{
    peername = name;
    peerip = ip;
    peerport = port;
    peernum = numb;
    peerteam = 3;
}

