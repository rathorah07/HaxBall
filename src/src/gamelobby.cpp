#include <iostream>
#include "gamelobby.h"
#include "ui_gamelobby.h"
#include "variables.h"
#include <QMessageBox>
#include <unistd.h>
#include <QDebug>
#include "global_data.h"
using namespace std;



gamelobby::gamelobby(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamelobby)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);

    if(host)
        return;

    connect(this,SIGNAL(startclicked()),this,SLOT(connecting_msg()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));

}

gamelobby::~gamelobby()
{
    delete ui;
}

void gamelobby::on_namebutton_clicked()
{
    ui->namebutton->setDown(false);
    string temp = ui->myplayername->text().toStdString();
    if(temp =="\0")
    {
        QMessageBox messageBox;
        ui->namebutton->setChecked(false);
        messageBox.critical(0,"Error","Playername can not be empty!");
        messageBox.setFixedSize(500,200);
        return;
    }

    playername = ui->myplayername->text().toStdString();
    if(ui->radioButton->isChecked() == true)
    {    singleplayer =true;
        Aipresent = true;

    }

    name_set=true;

    this->close();

    usleep(10000);

    if(singleplayer)
    {
        teampage = new Teamjoin(this);
        teampage->show();
        peerdata p(ui->myplayername->text().toStdString(),myip,myportnum,gamers.size()+1);
        gamers.push_back(p);
    }

    if(host && singleplayer==false)
    {
        teampage = new Teamjoin(this);
        teampage->show();
    }
    else if(Aipresent == false)
        emit startclicked();
}

void gamelobby::on_radioButton_2_clicked()
{
    ui->radioButton->setChecked(false);
}

void gamelobby::on_radioButton_clicked()
{
    ui->radioButton_2->setChecked(false);
}

void gamelobby::connecting_msg()
{
    progress = new progressbar(this);
    progress->show();
    timer.start(1000);
}

void gamelobby::update()
{

    if(state_connected)
    {
        progress->close();
        teampage = new Teamjoin(this);
        teampage->show();
        timer.stop();
    } 
}
