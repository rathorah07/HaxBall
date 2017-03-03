#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "glwidget.h"
#include "variables.h"
#include <QKeyEvent>
#include "Constants.h"
#include <unistd.h>
#include "gamelobby.h"
#include <SFML/Audio.hpp>
#include <Constants.h>


int seccounter =00;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    myflag = false;


    ui->setupUi(this);
    timer = new QTimer(this);
    if(vecmessages.size() !=0)
    {
        loadmessagelist();
    }


    mincounter=5;
    connect(&game_signal,SIGNAL(message_receive(QString)),this,SLOT(addmessage(QString)));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateclock()));
    connect(&game_signal,SIGNAL(goal_score(int)),this,SLOT(handle_score(int)));
    connect(&game_signal,SIGNAL(first_hit()),this,SLOT(start_time()));
    timer->start(1000);
    counter = 0;
    startnow = true;
    ui->clock->setText("5:00");
    QFont font = ui->clock->font();
    font.setPointSize(22);
    font.setBold(true);
    ui->clock->setFont(font);
    ui->glabel->hide();
    bg.loadFromFile("../assets/bgsound.wav");
    end.loadFromFile("../assets/endsound.wav");
    hit.loadFromFile("../assets/hit.wav");
    goal.loadFromFile("../assets/goal.wav");
    bgsound.setBuffer(bg);
    bgsound.setLoop(true);
    hitsound.setBuffer(hit);
    goalsound.setBuffer(goal);
    endsound.setBuffer(end);
    bgsound.play();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::updateclock()
{
    if(!disco)
    {
    if(myflag == true)
    {
        if(counter >= 3)
        {
            myflag = false;
            ui->glabel->close();
            goalsound.stop();
            bgsound.play();
            playing =true;
        }
        counter++;
    }

    else if(mincounter == 0 && seccounter ==0)
    {
        static int i= 0;
        startnow =false;
        if(i == 0 )
        {
          bgsound.stop();
          end_image();
          init_system();
          if(count_left != count_right)
          endsound.play();
        }


        else if(endsound.getStatus() == sf::Sound::Stopped && i >=3)
        {
            this->close();
        }
        i++;
    }


    else
    {
        if(seccounter==0)
        {
            seccounter = 59;
            mincounter--;
        }
        else
        {
            seccounter--;
        }
        QString ssecond = QString::number(seccounter);
        if(seccounter<10)
        {
            ssecond = "0" + ssecond;
        }
        ui->clock->setText(QString::number(mincounter) + ":"+ ssecond);
        QFont font = ui->clock->font();
        font.setPointSize(20);
        font.setBold(true);
        ui->clock->setFont(font);
    }
    }

    else
    {
        static int i=0;
        if(i==0)
        {
            QPixmap mypic(":/images/disconnect.jpg");
             ui->glabel->setPixmap(mypic);
             ui->glabel->show();
        }
        i++;
    }
}

void GameWindow::keyPressEvent( QKeyEvent *event )
{
    if(event->key()== Qt::Key_Up  && event->isAutoRepeat()==false)
    {
        up1 = true;
    }

    if(event->key()==Qt::Key_Down && event->isAutoRepeat()==false)
    {
         down1 = true;
    }

    if(event->key()==Qt::Key_Left && event->isAutoRepeat()==false)
    {
         left1 = true;
    }

    if(event->key()==Qt::Key_Right && event->isAutoRepeat()==false)
    {
         right1 = true;
    }

    if(event->key()==Qt::Key_Space && event->isAutoRepeat()==false)
    {
         hit1 = true;
         if(hitsound.getStatus() == sf::Sound::Playing)
             hitsound.stop();
         hitsound.play();
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Up  && event->isAutoRepeat()==false)
    {
        up1 = false;
    }

    if(event->key()==Qt::Key_Down && event->isAutoRepeat()==false)
    {
         down1 = false;
    }

    if(event->key()==Qt::Key_Left && event->isAutoRepeat()==false)
    {
         left1 = false;
    }

    if(event->key()==Qt::Key_Right && event->isAutoRepeat()==false)
    {
         right1 = false;
    }

    if(event->key()==Qt::Key_Space && event->isAutoRepeat()==false)
    {

         hit1 = false;
    }
}

void GameWindow::end_image()
{


    if(count_left > count_right)
    {
        QPixmap mypic(":/images/bluewins.png");
         ui->glabel->setPixmap(mypic);
    }

    else if(count_right > count_left)
    {
        QPixmap mypic(":/images/redwins.png");
         ui->glabel->setPixmap(mypic);
    }

    else
    {
        QPixmap mypic(":/images/draw.jpg");
        ui->glabel->setPixmap(mypic);
    }
    ui->glabel->show();
}

void GameWindow::handle_score(int i)
{   playing =false;
    startnow =false;
    bgsound.stop();
    if(goalsound.getStatus() == sf::Sound::Playing)
        goalsound.stop();
    goalsound.play();

    if(i==1)
    {
        QPixmap mypic(":/images/redscore.png");
         ui->glabel->setPixmap(mypic);
    }
    else if(i==2)
    {
        QPixmap mypic(":/images/bluescore.png");
         ui->glabel->setPixmap(mypic);
    }
    ui->glabel->show();
    QString temp = QString::fromStdString(to_string(count_right) + " : " +to_string(count_left));
    ui->showgoal->setText(temp);
    myflag = true;
    counter =0 ;
}

void GameWindow::start_time()
{
    startnow = true;
}

void GameWindow::loadmessagelist()
{
    messcounter =vecmessages.size() - 1;
    for(int i =0;i<vecmessages.size();i++)
    {
        ui->chatbox_2->addItem(vecmessages[i]);
    }
}

void GameWindow::on_Message_returnPressed()
{
    QString message_string = ui->Message->text();
    ui->Message->setText("\0");

    message_string = QString::fromStdString(playername) + " :  " + message_string;
    vecmessages.push_back(message_string);
    my_message = message_string.toStdString();
    mess = true;
    ui->chatbox_2->addItem(message_string);
    messcounter = counter+1;
    ui->chatbox_2->setCurrentRow(messcounter);
}
void GameWindow::addmessage(QString input)
{
    vecmessages.push_back(input);
    ui->chatbox_2->addItem(input);
    messcounter ++;
    ui->chatbox_2->setCurrentRow(messcounter);
}
