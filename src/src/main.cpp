#include "gamelobby.h"
#include <QApplication>
#include <iostream>
#include <GL/gl.h>
#include <pthread.h>
#include <stdlib.h>
#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "variables.h"
#include "Gamestate.h"
#include "helperfunc.h"
#include "connection.h"
#include "readpacket.h"
#include "writepackets.h"
#include <unistd.h>

using namespace std;


void * connection_thread(void *)
{
    while(name_set==false)
    {
        usleep(10000);
    }
    if(singleplayer == true)
        return NULL;
    connection();
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t connector;
    if(argc == 2)
    {
      host = 1;
      myportnum = atoi(argv[1]);
      hostportnum = myportnum;
      hostip = "localhost";
      myip = "localhost";
    }
    else if(argc == 5)
    {
      host = 0;
      myportnum = atoi(argv[1]);
      hostportnum = atoi(argv[2]);
      hostip = argv[3];
      myip = argv[4];
    }
    else
    {
      printf("invaid input! Please refer readme\n");
      exit(0);
    }

    int rc = pthread_create(&connector,NULL,connection_thread,NULL);
    initialize(0.9, -0.9, 0.9, -0.9, 2.25);
    QApplication a(argc, argv);
    gamelobby w;
    w.show();
    main_object = &w;
    return a.exec();
}
