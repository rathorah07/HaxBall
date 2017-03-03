#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pthread.h>
//#include "Socket.h"
#include "variables.h"
#include "packetheader.h"
#include "enet_host.h"
#include "enet_guest.h"

//TODO : enet_host.h
//#include "guest.h"
//#include "host.h"
using namespace std;






// arguments : is_host(boolean) , myport, hostport , hostip
int connection()
{

	int is_host = host;
	int myport= myportnum;
	if(is_host==1)
	{
		be_host(myport);
	}
	else
	{
		int hostport = hostportnum;
		be_guest(myport,hostport,hostip,myip);
	}

	return 0;
}

