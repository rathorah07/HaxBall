#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#include <QtCore>
#include <QObject>
using namespace std;

class MySignal : public QObject
{
    Q_OBJECT
public:
    MySignal();
    ~MySignal();

signals:
    void newpeeradded();
    void peerdisconnected();
    void dragged();
    void startgame();
    void goal_score(int);
    void message_receive(QString);
    void draw();
    void first_hit();
    void self_added();
};

#endif // MYSIGNAL_H
