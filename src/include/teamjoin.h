#ifndef TEAMJOIN_H
#define TEAMJOIN_H

#include <QMainWindow>
#include <QStringListModel>
#include <QTimer>
#include "gamewindow.h"
#include <QMouseEvent>
#include "gamemode.h"

using namespace std;
namespace Ui {
class Teamjoin;
}

class Teamjoin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teamjoin(QWidget *parent = 0);
    ~Teamjoin();
    GameWindow * game;
    gamemode *gamingmode;

private slots:

    void refresh();

    void on_StartButton_clicked();

    void update();

    void loadlist();

    void loadvector();

    void on_pushButton_clicked();

    void addmessage(QString);

private:
    Ui::Teamjoin *ui;
    QStringListModel *TeamA;
    QStringListModel *TeamB;
    QStringListModel *NeutralTeam;

    QTimer timer;
    int counter;

};

#endif // TEAMJOIN_H
