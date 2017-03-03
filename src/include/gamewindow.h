#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QString>
#include <SFML/Audio.hpp>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTimer *timer;
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    bool myflag;
    bool startnow;
    int counter;
    int messcounter;

    sf::SoundBuffer bg;
    sf::SoundBuffer hit;
    sf::SoundBuffer goal;
    sf::SoundBuffer end;

    sf::Sound bgsound;
    sf::Sound hitsound;
    sf::Sound goalsound;
    sf::Sound endsound;

private slots:
    void updateclock();
    void end_image();
    void handle_score(int);
    void start_time();

    void on_Message_returnPressed();
    void loadmessagelist();
    void addmessage(QString);


private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
