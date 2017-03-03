#include "glwidget.h"

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include "Display.h"
#include "Player.h"
#include "Ball.h"
#include "Interaction.h"
#include "Collisions.h"
#include "Detect_Goal.h"
#include "Constants.h"
#include "States.h"
#include "Positions.h"
#include "variables.h"
#include "mysignal.h"
#include <unistd.h>

using namespace std;
float PI = 3.141592;
bool temp;
int countter=0;

GlWidget::GlWidget(QWidget *parent):
    QGLWidget(parent)
{
    connect(&game_signal,SIGNAL(draw()),this,SLOT(updateGL()));
    QGLWidget::setFormat(QGLFormat(QGL::SampleBuffers));
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    if(singleplayer==true)
        timer.start(16);
}

GlWidget::~GlWidget()
{

}

void GlWidget::initializeGL()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_MULTISAMPLE_ARB);
    glEnable(GL_MULTISAMPLE);
}

void GlWidget::paintGL()
{
        glClear(GL_COLOR_BUFFER_BIT);
        if(!disco)
        {
            if(playing)
            {
                calculate();
            }
            drawing();
        }

}

void GlWidget::drawing()
{
    stadium1();
    create_ball(freedom);
    for(int j = 1; j < players.size(); j++){
        create_player(players[j]);
    }
}

void GlWidget::calculate()
{   if(Aipresent==false)
    {

    goal = false;
    freedom.pos[0] = Positions[0].x;
    freedom.pos[1] = Positions[0].y;
    freedom.vel[0] = Positions[0].vx;
    freedom.vel[1] = Positions[0].vy;
    for(int i = 1; i < Positions.size(); i++){
        players[i].pos[0] = Positions[i].x;
        players[i].pos[1] = Positions[i].y;
        players[i].vel[0] = Positions[i].vx;
        players[i].vel[1] = Positions[i].vy;
        players[i].in_contact = Positions[i].in_contact;
        players[i].hit = Positions[i].hit;
        players[i].direction._vector[0] = Positions[i].dx;
        players[i].direction._vector[1] = Positions[i].dy;
    }
    // noremal

    for(int k = 1; k < players.size(); k++){
        collision(players[k], freedom);
    }

    for(int p = 1; p < players.size(); p++){
        for(int q = p + 1; q < players.size(); q++){
                collision_players(players[p], players[q]);
        }
    }


    check_post(freedom);
    detect_goal();
    move_system();
    for(int m = 1; m < players.size(); m++){
        players[m].hit = false;
    }

    keySpecialOperations();
    Positions[0].x = freedom.pos[0];
    Positions[0].y = freedom.pos[1];
    Positions[0].vx = freedom.vel[0];
    Positions[0].vy = freedom.vel[1];
    Positions[0].in_contact = freedom.in_contact;

    for(int i = 1; i < Positions.size(); i++){
        Positions[i].x = players[i].pos[0];
        Positions[i].y = players[i].pos[1];
        Positions[i].vx = players[i].vel[0];
        Positions[i].vy = players[i].vel[1];
        Positions[i].in_contact = players[i].in_contact;
        Positions[i].hit = players[i].hit;
        Positions[i].dx = players[i].direction._vector[0];
        Positions[i].dy = players[i].direction._vector[1];
    }
    }
    else
    {
        goal = false;
            freedom.pos[0] = Positions[0].x;
            freedom.pos[1] = Positions[0].y;
            freedom.vel[0] = Positions[0].vx;
            freedom.vel[1] = Positions[0].vy;
            for(int i = 1; i < Positions.size(); i++){
                players[i].pos[0] = Positions[i].x;
                players[i].pos[1] = Positions[i].y;
                players[i].vel[0] = Positions[i].vx;
                players[i].vel[1] = Positions[i].vy;
                players[i].in_contact = Positions[i].in_contact;
                players[i].hit = Positions[i].hit;
                players[i].direction._vector[0] = Positions[i].dx;
                players[i].direction._vector[1] = Positions[i].dy;
            }
            // noremal

            for(int k = 1; k < players.size(); k++){
                collision(players[k], freedom);
            }

            for(int p = 1; p < players.size(); p++){
                for(int q = p + 1; q < players.size(); q++){
                        collision_players(players[p], players[q]);
                }
            }


            check_post(freedom);
            detect_goal();
            move_system();
            for(int m = 1; m < players.size(); m++){
                players[m].hit = false;
            }

            keySpecialOperations();
            bot.move_bot(players[num_riders], freedom);
            Positions[0].x = freedom.pos[0];
            Positions[0].y = freedom.pos[1];
            Positions[0].vx = freedom.vel[0];
            Positions[0].vy = freedom.vel[1];
            Positions[0].in_contact = freedom.in_contact;

            for(int i = 1; i < Positions.size(); i++){
                Positions[i].x = players[i].pos[0];
                Positions[i].y = players[i].pos[1];
                Positions[i].vx = players[i].vel[0];
                Positions[i].vy = players[i].vel[1];
                Positions[i].in_contact = players[i].in_contact;
                Positions[i].hit = players[i].hit;
                Positions[i].dx = players[i].direction._vector[0];
                Positions[i].dy = players[i].direction._vector[1];
            }
    }
}

void GlWidget::resizeGL(int width,int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    myratio = (1.0*width)/height;
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D ((GLdouble)(-myratio), (GLdouble)myratio,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    leftp = -(myratio*0.9);
    rightp = myratio*0.9;
    bottom = -0.8;
    top = 0.8;
}

void GlWidget::stadium1()
{
    GLfloat top_corner = top, bottom_corner = bottom ,left_corner = leftp, right_corner = rightp,helper = 2.25;

    glColor3f(0.2, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.96*myratio,-0.96);
    glVertex2f(-0.96*myratio,0.96);
    glVertex2f(0.96*myratio,0.96);   // get window width
    glVertex2f(0.96*myratio,-0.96);
    glEnd();

    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(left_corner,bottom_corner);
    glVertex2f(left_corner,top_corner);
    glVertex2f(right_corner,top_corner);   // get window width
    glVertex2f(right_corner,bottom_corner);
    glEnd();

    glLineWidth(5.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left_corner,top_corner/helper);
    glVertex2f(left_corner-0.05*myratio,top_corner/helper);
    glVertex2f(left_corner-0.05*myratio, bottom_corner/helper);
    glVertex2f(left_corner, bottom_corner/helper);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(right_corner,top_corner/helper);
    glVertex2f(right_corner+0.05*myratio,top_corner/helper);
    glVertex2f(right_corner+0.05*myratio, bottom_corner/helper);
    glVertex2f(right_corner, bottom_corner/helper);
    glEnd();

    glLineWidth(4.0);
    glColor3f(0.8,0.6,0.8);

    glBegin(GL_LINE_LOOP);
    glVertex2f(left_corner,bottom_corner);
    glVertex2f(left_corner,top_corner);
    glVertex2f(right_corner,top_corner);   // get window width
    glVertex2f(right_corner,bottom_corner);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0,top_corner);
    glVertex2f(0.0,bottom_corner);
    glEnd();
    drawcircle(0.0,0.0,(2*top_corner)/3,4,1);

    glColor3f(0.8,0.1,0.1);
    glBegin(GL_LINES);
    glVertex2f(right_corner, top_corner/helper);
    glVertex2f(right_corner, bottom_corner/helper);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(left_corner,top_corner/helper);
    glVertex2f(left_corner,bottom_corner/helper);
    glEnd();
    glColor3f(0.3,0.0,0.6);
    drawcircle(left_corner,top_corner/helper,0.05,4,0);
    drawcircle(left_corner,bottom_corner/helper,0.05,4,0);
    drawcircle(right_corner,top_corner/helper,0.05,4,0);
    drawcircle(right_corner,bottom_corner/helper,0.05,4,0);

    glFlush();
}

void GlWidget::drawcircle(GLfloat x ,GLfloat y ,GLfloat r,int quads,bool unfilled)
{
    double mypi = 3.14159265359/2;
    double delta = mypi/100;
    double max = quads*mypi;

    double x1 = 0.0, y1 = 0.0;
    if(unfilled==true)
    {
        glBegin(GL_LINE_LOOP);
    }
    else
    {
        glBegin(GL_POLYGON);
    }
    for(double d =0; d<max;d += delta)
    {
        x1 = x + r*sin(d);
        y1 = y + r * cos(d);

        glVertex2f(x1,y1);
    }
    glEnd();
}

void GlWidget::create_player(player rider)
{
    glColor3f(rider.color[0], rider.color[1], rider.color[2]);
    drawcircle(rider.pos[0], rider.pos[1], rider.radius, 4, false);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    drawcircle(rider.pos[0], rider.pos[1], rider.radius + 0.01, 4, true);
}

void GlWidget::create_ball(ball freedom)
{
    glColor3f(freedom.color[0], freedom.color[1], freedom.color[2]);
    drawcircle(freedom.pos[0], freedom.pos[1], freedom.radius, 4, false);
}
