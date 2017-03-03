#include <iostream>
#include "teamjoin.h"
#include "ui_teamjoin.h"
#include "variables.h"
#include "helperfunc.h"
#include <QtCore>
#include <QDebug>
#include <QMouseEvent>
#include "global_data.h"
#include "mysignal.h"
#include "Constants.h"

using namespace std;


Teamjoin::Teamjoin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Teamjoin)
{
    counter = -1;
    ui->setupUi(this);
    ui->TeamA_listview->acceptDrops();
    connect(&game_signal,SIGNAL(newpeeradded()),this,SLOT(loadlist()));
     connect(&game_signal,SIGNAL(message_receive(QString)),this,SLOT(addmessage(QString)));
    connect(&timer, SIGNAL(timeout()),this,SLOT(loadvector()));
    connect(&game_signal,SIGNAL(dragged()),this,SLOT(loadlist()));
    connect(&game_signal,SIGNAL(startgame()),this,SLOT(on_StartButton_clicked()));
    timer.start(2000);
    TeamA = new QStringListModel(this);
    TeamB = new QStringListModel(this);
    NeutralTeam = new QStringListModel(this);
    loadlist();
    ui->chatbox->setSpacing(2);
    if(singleplayer == true)
    {
        on_pushButton_clicked();
        ui->pushButton->setDisabled(true);
    }
    else if(!host && singleplayer==false)
    {
        ui->StartButton->setDisabled(true);
        ui->StartButton->setVisible(false);
        ui->NeutralTeam_listview->setDragEnabled(false);
        ui->TeamA_listview->setDragEnabled(false);
        ui->TeamB_listview->setDragEnabled(false);
        ui->pushButton->setDisabled(true);
        ui->pushButton->setVisible(false);
    }

}

Teamjoin::~Teamjoin()
{
    delete ui;
}

void Teamjoin::refresh()
{
    QStringList mylist = TeamA->stringList();
    foreach (QString itm,mylist) {
            gamers[find_peerpos(itm.toStdString())].peerteam = 0;
    }

    mylist.clear();

    mylist = TeamB->stringList();
    foreach (QString itm,mylist) {
            gamers[find_peerpos(itm.toStdString())].peerteam = 1;
    }
    mylist.clear();

    mylist = NeutralTeam->stringList();
    foreach (QString itm,mylist) {
            gamers[find_peerpos(itm.toStdString())].peerteam = 3;
    }
    mylist.clear();
    loadlist();
}


void Teamjoin::on_StartButton_clicked()
{
    loadvector();
    this->close();

    if(singleplayer == true)
    {
        init_system();
    }
    
    for(int i=0;i<gamers.size();i++)
    {
        cout<<gamers[i].peername << " " <<gamers[i].peerteam <<" " <<gamers[i].peernum<<endl;
    }

    game_mode = true;
    game = new GameWindow(this);
    game->show();
}

void Teamjoin::update()
{
    QString message_string = ui->Message->text();
    ui->Message->setText("\0");

    message_string = QString::fromStdString(playername) + " :  " + message_string;
    vecmessages.push_back(message_string);
    my_message = message_string.toStdString();
    mess = true;
    ui->chatbox->addItem(message_string);
    counter = counter+1;
    ui->chatbox->setCurrentRow(counter);
}

void Teamjoin::addmessage(QString input)
{
    cout<<"addmessage"<<endl;
    vecmessages.push_back(input);
    ui->chatbox->addItem(input);
    counter = counter+1;
    ui->chatbox->setCurrentRow(counter);
}

void Teamjoin::loadlist()
{
    QStringList TeamAlist,TeamBlist,NeutralTeamlist;
    QString filename;

    for(int i=0;i<gamers.size();i++)
    {
        filename = QString::fromStdString(gamers[i].peername);

        if(gamers[i].peerteam == 3)
        {
           NeutralTeamlist.append(filename);
        }

        if(gamers[i].peerteam == 0)
        {
           TeamAlist.append(filename);
        }

        if(gamers[i].peerteam == 1)
        {
           TeamBlist.append(filename);
        }

    }

    TeamA->setStringList(TeamAlist);
    TeamB->setStringList(TeamBlist);
    NeutralTeam->setStringList(NeutralTeamlist);

    ui->TeamA_listview->setModel(TeamA);
    ui->TeamB_listview->setModel(TeamB);
    ui->NeutralTeam_listview->setModel(NeutralTeam);

}

void Teamjoin::loadvector()
{
    bool flag =false;

    QStringList mylist = TeamA->stringList();
    foreach (QString itm,mylist) {
            if(gamers[find_peerpos(itm.toStdString())].peerteam != 0)
            {
                gamers[find_peerpos(itm.toStdString())].peerteam = 0;
                flag = true;
            }

    }

    mylist.clear();

    mylist = TeamB->stringList();

    foreach (QString itm,mylist) {
            if(gamers[find_peerpos(itm.toStdString())].peerteam != 1)
            {
                gamers[find_peerpos(itm.toStdString())].peerteam = 1;
                flag = true;
            }

    }

    mylist.clear();

    mylist = NeutralTeam->stringList();

    foreach (QString itm,mylist) {
            if(gamers[find_peerpos(itm.toStdString())].peerteam != 3)
            {
                gamers[find_peerpos(itm.toStdString())].peerteam = 3;
                flag = true;
            }

    }

    mylist.clear();
    if(TeamA->rowCount() + TeamB->rowCount() + NeutralTeam->rowCount() != gamers.size())
        loadlist();

    if(flag)
    {
       dragged = true;
    }


}


void Teamjoin::on_pushButton_clicked()
{
    ui->pushButton->setDown(false);

    if(ui->pushButton->text() == "ADD_AI")
    {
        Aipresent = true;
        peerdata ai("AI_BOT",myip,myportnum,gamers.size());
        gamers.push_back(ai);
        ui->pushButton->setText("REMOVE_AI");
    }
    else if(ui->pushButton->text() == "REMOVE_AI")
    {
            Aipresent = false;
            ui->pushButton->setText("ADD_AI");
            int i = find_peerpos("AI_BOT");
            gamers.erase(gamers.begin()+i);
    }
}
