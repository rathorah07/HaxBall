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
#include "helperfunc.h"
#include "Constants.h"
//#include "vectordata_tostring.h"


using namespace std;


static ENetAddress address;
static ENetHost * server; // We are making a P2P connection , hence client-server on each side.
static ENetEvent event,event2;
static vector<ENetPeer *> allpeers;
static ENetPeer  *peer;
static ENetPacket *packet;

static bool client_connect=false;
static char IP[4];
static string* ptr;



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


int connected=0;


int post_connect(int num)
{
  string s = "test paket";
    // cout << s << endl;
    packet = enet_packet_create((char *)s.c_str(),s.length(),
            ENET_PACKET_FLAG_RELIABLE);
       enet_peer_send(peer,0,packet);


     enet_host_flush(server);
   // while(client_connect==false)

    sleep(2);

     if(1) //if (enet_host_service(client, &event, 10000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
    {
      //client_connect=false;

        printf("Connection to %d succeeded.\n", num);
        allpeers.push_back(peer);
        connecthash[num]=1;
        connected++;

        return 1;
    } else {
      enet_peer_reset(peer);
      printf("Could not connect to %d.\n", num);
      return 0;
    }

}

int handle2(string input)
{
    input = input.erase(0,1);

    vector<peerdata> temp = readhost_firstpacket(input);

    gamers.clear();

    for(int i=0;i<temp.size();i++)
    {
    	gamers.push_back(temp[i]);
    }

    my_num = find_peerpos(playername)+1;
    // cout << "My_num is" << my_num << " " << gamers.size() << endl;
    connecthash[my_num]=1;
    connecthash[1]=1;
    if(my_num==gamers.size())
    {
      for(int i=0;i<gamers.size();i++)
        connecthash[gamers[i].peernum]=1;
          state_connected=true;
      return 0;
    }

    // cout << "Reached this checkpoint" << endl;

    for(int i=0;i<gamers.size();i++)
    {
        if(connecthash[gamers[i].peernum]==0)
        {
            // cout << "Peernum" << gamers[i].peernum << endl;
           enet_address_set_host(&address, (char *)(gamers[i].peerip).c_str());
           address.port = (gamers[i].peerport);
           peer = enet_host_connect(server, &address, 5, 0);
           post_connect(gamers[i].peernum);


        }
    }
    state_connected=true;

    return 0;
}

static int handle3(string input)
{
      input = input.erase(0,1);
      string message = readpacket_message(input);
      QString temp = QString::fromStdString(message);
      emit game_signal.message_receive(temp);
}
int handle4(string input)
{

    input = input.erase(0,1);

    vector<peerdata> temp = readpacket_dragdrop(input);

    gamers.clear();

    for(int i=0;i<temp.size();i++)
    {
      gamers.push_back(temp[i]);
    }
     state_connected=true;

     emit game_signal.dragged();
    return 1;

}




int handle5()
{
  game_mode=true;
  num_players=gamers.size();

  init_system();
  // cout<<"initializing"<<endl;

  // for(int i=0;i<Positions.size();i++)
  // {
  //     cout<<Positions[i].x << "  " <<Positions[i].y<<endl;
  // }


  for(int i=0;i<=num_players;i++)
            temp_pos[i]=Positions[i];
    //TODO SEND GAMERS VECTOR TO A FUNCTIOn which staRTS GAME
  emit game_signal.startgame();
  sendmydata=true;
}






static int waitgamedata()
{

       // cout << "WGD" << endl;
         for(int i=0;i<=num_players;i++)
         {
          if( (packethash[i]==0) )
            {
               if( (connecthash[i]==0 && i>0) || (i==0))
                continue;
              else
               {
           //     cout << i << " " << connecthash[i] << endl;
                return 0;
                }
            }
          }

         temp_pos[my_num] = Positions[my_num];
         temp_pos.swap(Positions);


        // cout << "Drawn game" << endl;
          emit game_signal.draw();
          //usleep(3000);

            memset(packethash,0,sizeof(packethash));
          for(int i=0;i<=num_players;i++)
            temp_pos[i]=Positions[i];
         sendmydata=true;

}

int handlegamedata(string input)
{

      //  cout << "HGD Called"  << endl;
        input = input.erase(0,1);
        int hashnum;
        Position p = readpacket_gamestate(input,hashnum);
        //  cout << hashnum << " " << my_num << endl;
//        cout<<"Position sent by other player"<<endl;
  //      cout<<p.x<<"  " <<p.y<<"  "<<p.dx<<" "<<p.dy<<endl;

        packethash[hashnum]=1;
        packethash[my_num]=1;
        temp_pos[hashnum]=p;
        waitgamedata();

}

int handleball(string input)
{
  //cout << "Received Ball pos " << endl;
  input = input.erase(0,1);
  Position p = readpacket_ballpos(input);
  temp_pos[0]=p;
  packethash[0]=1;
}

int handlehash(string input)
{
  input = input.erase(0,1);
  int num = readpacket_disconnect(input);
  connecthash[num]=0;
 // cout << "HANDLED HASH" << endl;
  waitgamedata();
}




int handle_guest_packet(string input)
{

    switch(input[0])
    {
        case '1' :
            //handle1(input);
            break;

        case '2' :
            // host first packet;
            handle2(input);
            break;

        case '3' :
              handle3(input);
            // game start functions
            break;

        case '4' :
            handle4(input);
           break;


         case '5' :
         handle5();
         break;


        case '7' :
          handlegamedata(input);
          break;


        case '@' :
          handleball(input);
          break;


        case '#' :
          handlehash(input);
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



int be_guest(int myport,int hostport,string ip,string myip)
{

  memset(connecthash,0,sizeof(connecthash));


  /*
  ENetHost  *client,*server; //P2P connection
  ENetAddress  address;
  ENetEvent  event;

  ENetPacket  *packet; */


	if (enet_initialize() != 0)
	{
     printf("Could not initialize enet.");
     return 0;
	}





	   string x=  ip ;


	  address.host = ENET_HOST_ANY;
    address.port = myport;


    server = enet_host_create (&address /* the address to bind the server host to */,
                             32      /* allow up to 32 clients and/or outgoing connections */,
                              2      /* allow up to 2 channels to be used, 0 and 1 */,
                              0      /* assume any amount of incoming bandwidth */,
                              0      /* assume any amount of outgoing bandwidth */);




    if (server == NULL) {

          printf("Could not start server.\n");
          return 0;
    }




	   enet_address_set_host(&address, (char *)x.c_str());
     address.port = hostport;




	   peer = enet_host_connect(server, &address, 2, 0);



	  if (peer == NULL)
	  {
	    printf("Could not connect to server\n");
	    return 0;
	  }






	 if (enet_host_service(server, &event, 1) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
	  {

      event.peer->data  = (void *)"Am";
      num_players++;
	    printf("Connection to %s succeeded.\n", "HOST");
	    allpeers.push_back(peer);
        connecthash[1]=1;
	    connected++;




	    string S = writepeer_Firstpacket(playername,myip,myportnum);

	    packet = enet_packet_create((char *)S.c_str(), S.length(),
          ENET_PACKET_FLAG_RELIABLE);
	    enet_peer_send(peer, 0, packet);
	    // cout << "PACKET SENT" << endl;


        int ran = (int)event.peer->address.host   ;
       IP[0] =  ran&0xff; ran>>=8;
        IP[1] = ran&0xff; ran>>=8;
        IP[2] = ran&0xff; ran>>=8;
        IP[3] = ran&0xff;
        ptr = new string;

        *ptr=makeipstring();
      //  cout << *ptr  << endl;
        event.peer->data  = (char *)(ptr->c_str());
       // cout << "XYZ" << endl;

	  } else {
	    enet_peer_reset(peer);
	    printf("Could not connect to %s.\n", "HOST");
	    return 0;
	  }


     	while(1)
	{
	  // cout << "INFDAFS" << endl;
        while(enet_host_service(server,&event,10)>0)
		{

			switch(event.type)
			{
          case ENET_EVENT_TYPE_DISCONNECT:
            printf ("%s disconnected.\n", event.peer -> data);
            /* Reset the peer's client information. */
            {
              string ip = (const char*)event.peer->data;
             int discopos = findip_pos(ip) ;
            //  cout << "Discopos is " << discopos << endl;
             connecthash[discopos]=0;

             event.peer -> data = NULL;
             connected--;

           }

          break;

				case ENET_EVENT_TYPE_CONNECT:

        {
          num_players++;
        cout  << "Connect event" << endl;
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
     //   cout << "XYZ" << endl;
      }


        break; // Nothing to do until the client actually sends a packet

				case ENET_EVENT_TYPE_RECEIVE:

				{

                // cout << "RECEIVED" << endl;
        		string packet_message = (char *)event.packet->data;
        	 //cout << packet_message << endl;


        		handle_guest_packet(packet_message);

          }
        		 break;




			}

		}

     if(sendmydata==true)
     {
            //       usleep(5000);
            sendmydata=false;
            // cout<<"sending gamestate doubt"<<endl;
            //cout<<"Position vector is " <<endl;
            /*for(int i=0;i<Positions.size();i++)
            {
                cout<<Positions[i].x<<"  "<<Positions[i].y<<"  "<<Positions[i].dx<<"  "<<Positions[i].dy <<endl;
            }*/
            string S = writepacket_gamestate(Positions,my_num);//writepacket_startgame();
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            //int y=enet_peer_send(peer,0,packet);
            enet_host_broadcast(server , 0, packet);
            //cout << "Brodacasted" << x << endl;
            //cout << "PACKET SENT"  << endl;

         }

         if( mess == true)
         {
            mess = false;
            string S = writepacket_message(my_message);
            packet = enet_packet_create((char *)S.c_str(), S.length(),ENET_PACKET_FLAG_RELIABLE);
            enet_host_broadcast(server , 0, packet);
         }
         if(connecthash[1]==0)
         {
            cout << "CONNECTHASHED" << endl;
             disco=true;

         }
	}





	  enet_deinitialize();




}
