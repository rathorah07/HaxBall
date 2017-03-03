//#include <iostream>

#ifndef packetheader_H
#define packetheader_H
#include <string>
#include <sstream>

using namespace std;


class packetheader
{
public:
int owner; // ranked by their connection number
int type;
int sno ;  // sno
int ack;
packetheader(int a=0,int b=0,int c=0,int d=0)
{
	owner=a;
	type=b;
	sno=c;
	ack=d;
}
string phead;
string get_phead()
{
	phead = "*";
	phead +=  to_string(owner);
	phead += "*" + to_string(type);
	phead += "*" + to_string(sno);
	phead += "*" + to_string(ack);
	phead += "*#";
	return phead;
}
int extract_phead(string temp) // return position of # i.e end of packet header.
{
	int j=1;
	while(temp[j]!='*')
	{	
		owner = 10*owner + (temp[j]-'0');
		j++;
	}
	j++;
		while(temp[j]!='*')
	{	
		type = 10*type + (temp[j]-'0');
		j++;
	}
	j++;
		while(temp[j]!='*')
	{	
		sno = 10*sno + (temp[j]-'0');
		j++;
	}
	j++;
	while(temp[j]!='*')
	{	
		ack = 10*ack + (temp[j]-'0');
		j++;
	}
	j++;
	return j;
}

};

#endif
/*
int main()
{
	packetheader a(1,1,1,0);
	cout << a.get_phead();
}
*/
