#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include "Player.h"
#include "Ball.h"
#include <QTimer>
#include <QImage>

class GlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GlWidget(QWidget *parent =0);
    ~GlWidget();
    QTimer timer;
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
    void stadium1();
    void drawcircle(GLfloat x ,GLfloat y ,GLfloat r,int quads,bool unfilled);
    void create_player(player rider);
    void create_ball(ball freedom);
    void drawing();
    QImage Red_score;
    QImage Blue_score;
    QImage Red_wins;
    QImage Blue_wins;


public slots:
    void calculate();
};

#endif // GLWIDGET_H
