#ifndef PEERDATA_H
#define PEERDATA_H
#include <iostream>
#include <string>
using namespace std;

class peerdata{
public:
    string peername;
    string peerip;
    int peerport;
    int peernum;
    int peerteam;

    peerdata();

    peerdata(string name,string ip,int port,int numb);

};
#endif // PEERDATA_H
