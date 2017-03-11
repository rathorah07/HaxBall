#include <QtCore>
#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>
#include <enet/enet.h>
#include "variables.h"
#include "packetheader.h"
#include "readpacket.h"
#include "writepackets.h"
#include "global_data.h"
#include "peerdata.h"
#include "mysignal.h"
#include "Constants.h"

using namespace std;

static int connected=0;
static ENetAddress address;
static ENetHost * server; // We are making a P2P connection , hence client-server on each side.
static ENetEvent event;
static vector<ENetPeer *> allpeers;
static ENetPeer  *peer,*peernew;
static ENetPacket *packet;

bool client_connect=false;

static char IP[4];
static string *ptr;


static string makeipstring()
{
  string S;
  S = to_string((int)IP[0]);
  for(int i=1;i<=3;i++)
  {
    S+=".";
    S+=to_string((int)IP[i]);
  }
  return S;
}


int handle1(string input)
{
    input = input.erase(0,1);
    packet1_data obj = readpeer_Firstpacket(input);
    string nick = obj.nickname;
    string ip = obj.ip;
    int  port = obj.port;
    num_players++;
    peerdata p = peerdata(nick,ip,port,num_players);
    gamers.push_back(p);

        connecthash[num_players]=1;
        connected++;

      return 0;



}

static int handle3(string input)
{
      input = input.erase(0,1);
      string message = readpacket_message(input);
      QString temp = QString::fromStdString(message);
      emit game_signal.message_receive(temp);
}


static int waitgamedata()
{

        if(Aipresent)
        packethash[AInum]=1;
        packethash[my_num]=1;
        packethash[0] = 1;

        // cout << "WGD" << endl;
    for(int i=1;i<=num_players;i++)
         {
          if( (packethash[i]==0) )
          {
            if(connecthash[i]==0 && i>0)
              continue;
            else
            {
                // cout << i << " " << connecthash[i] << endl;
              return 0;

            }
          }

         }


         if(Aipresent)
          temp_pos[AInum] = Positions[AInum];

         temp_pos[my_num] = Positions[my_num];
         temp_pos[0] = Positions[0];
         //cout<<"swapping vector"<<endl;

         Positions.swap(temp_pos);
        /* cout<<"Position after swapped"<<endl;
         for(int i=0;i<Positions.size();i++)
         {
             cout<<Positions[i].x<<"  "<<Positions[i].y<<"  "<<Positions[i].dx<<"  "<<Positions[i].dy <<endl;
         }
         */

         emit game_signal.draw();
        // usleep(3000);


          //  cout << "Drawn game" << endl;

         sendmydata=true;
         memset(packethash,0,sizeof(packethash));

}

static int handlegamedata(string input)
{

        // cout << "HGD Called"  << endl;
        input = input.erase(0,1);
        int hashnum;
        Position p = readpacket_gamestate(input,hashnum);
      //  cout << hashnum << " " << my_num << endl;
        packethash[hashnum]=1;
        packethash[my_num]=1;
        temp_pos[hashnum]=p;
         waitgamedata();

}

int handle_packet(string input)
{

    switch(input[0])
    {
        case '1' :
            handle1(input);
            break;

        case '2' :
            // host first packet;
            input = input.erase(0,1);
            readhost_firstpacket(input);
            break;

        case '3' :
              handle3(input);
              break;
            // game start functions
            break;

        case '7' :
            handlegamedata(input);
            break;

       /* case '4' :
            // Game state Packet
            input =input.erase(0,1);
            readpacket_gamestate(input);
            break; */

        default :
            // other packets break;
        break;
    }
}



int be_host(int myport)
{


  memset(connecthash,0,sizeof(connecthash));
    connecthash[1]=1; // Connected to Host.
    my_num=1;



	if (enet_initialize() != 0)
	{
     printf("Could not initialize enet.");
     return 0;
	}



    address.host = ENET_HOST_ANY;
	address.port = myport;


	server = enet_host_create (& address /* the address to bind the server host to */,
                             32      /* allow up to 32 clients and/or outgoing connections */,
                              2      /* allow up to 2 channels to be used, 0 and 1 */,
                              0      /* assume any amount of incoming bandwidth */,
                              0      /* assume any amount of outgoing bandwidth */);




	if (server == NULL) {

		    printf("Could not start server.\n");
	    	return 0;
	}



    peerdata p = peerdata(playername,myip,myportnum,1);//Pushing Host
    gamers.push_back(p);

	while(1)
	{

        while(enet_host_service(server,&event,10)>0)
		{
			 //cout << "IN" << endl;
      //cout << event.type << endl;

          switch(event.type)
      {
          case ENET_EVENT_TYPE_DISCONNECT:
          {

              printf ("%s disconnected.\n", event.peer -> data);
             /* Reset the peer's client information. */
             string ip = (const char*)event.peer->data;
             int discopos = findip_pos(ip);
            //  cout << "Discopos is " << discopos << endl;
             connecthash[discopos]=0;

            string  S = writepacket_disconnect(discopos);
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            enet_host_broadcast(server, 1, packet);

             event.peer -> data = NULL;
             connected--;
              waitgamedata();


           }
          break;

        case ENET_EVENT_TYPE_CONNECT:
        //event.peer->data  = (void *)"CLIENT";
      {
        // cout  << "Connect event" << endl;
          client_connect=true;
        printf ("A new client connected from %x:%u.\n",
                event.peer -> address.host,
                event.peer -> address.port);
        connected++;
       int ran = (int)event.peer->address.host   ;
       IP[0] =  ran&0xff; ran>>=8;
        IP[1] = ran&0xff; ran>>=8;
        IP[2] = ran&0xff; ran>>=8;
        IP[3] = ran&0xff;
        ptr = new string;

        *ptr=makeipstring();
        // cout << *ptr  << endl;
        event.peer->data  = (char *)(ptr->c_str());
        // cout << "XYZ" << endl;

      }


        break; // Nothing to do until the client actually sends a packet

        case ENET_EVENT_TYPE_RECEIVE:

        {
               // cout << "ENET_EVENT_TYPE_RECEIVE" << endl;
              /*  printf("A packet of length %u containing %s -was received from %s on channel %u.\n",  event.packet -> dataLength,
                event.packet -> data,
                event.peer -> data,
                event.channelID);*/
            /* Clean up the packet now that we're done using it. */
            //string message = string((char *)event.packet->data);
            //string owner = string((char *)event.peer->data);

            string packet_message = (char *)event.packet->data;

            //cout << packet_message << endl;



            handle_packet(packet_message);
            //TODO : function(message,owner);
            //TODO : BROADCAST PACKET

            //enet_packet_destroy (event.packet);
          }
             break;




          }



    }
        if(client_connect==true)
        {
              cout << "CLient_Connect if " << endl;
                client_connect=false;
                 string S = writehost_firstpacket(gamers);


               packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);

                           if(packet==NULL)
                // cout << "EMPTY packet" << endl;

              enet_host_flush(server);

              enet_host_broadcast(server, 0, packet);
              enet_host_flush(server);
              // cout << "PACKET SENT" << endl;

        }
        if(dragged==true)
        {
          dragged=false;
          string S = writepacket_hostdrag(gamers); // TO CHANGE

          packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
          enet_host_broadcast(server, 0, packet);
          // cout << "PACKET SENT" << endl;
          //enet_host_flush(client);

        }
        if(game_mode==true)
        {
            // cout<<"in game mode packet"<<endl;
          string S= writepacket_startgame();
          num_players=gamers.size();

          init_system();
          // cout<<"initializing"<<endl;
          // for(int i=0;i<Positions.size();i++)
          // {
          //     cout<<Positions[i].x << "  " <<Positions[i].y<<endl;
          // }
          packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
          enet_host_broadcast(server, 0, packet);
          // cout << "PACKET SENT" << endl;
          //enet_host_flush(client);

           if(Aipresent==true)
            AInum = gamers.size();
          sendmydata=true;
          game_mode=false;
        }
        if(sendmydata==true)
         {

            // cout<<"my data sent"<<endl;
            sendmydata=false;
            //cout<<"sending gamestate doubt"<<endl;
            //cout<<"Position vector is " <<endl;
            /*for(int i=0;i<Positions.size();i++)
            {
                cout<<Positions[i].x<<"  "<<Positions[i].y<<"  "<<Positions[i].dx<<"  "<<Positions[i].dy <<endl;
            }*/
            string  S = writepacket_ballpos(Positions);
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            enet_host_broadcast(server, 1, packet);


             if(Aipresent==true)
             {

                //int y = Positions.size() - 1;
                S = writepacket_gamestate(Positions,AInum);
                packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
                enet_host_broadcast(server, 1, packet);

             }

             S = writepacket_gamestate(Positions,my_num);
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            //int y=enet_peer_send(peer,0,packet);
            enet_host_broadcast(server, 1, packet);

            //cout << "PACKET SENT"  << endl;
            //enet_host_flush(client);

         }

         if( mess == true)
         {
            mess = false;
            string S = writepacket_message(my_message);
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            enet_host_broadcast(server , 0, packet);
         }

	}


	  enet_host_destroy(server);
	  enet_deinitialize();

	return 0;
}
