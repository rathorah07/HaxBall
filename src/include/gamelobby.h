#ifndef GAMELOBBY_H
#define GAMELOBBY_H

#include <QMainWindow>
#include "teamjoin.h"
#include "progressbar.h"
#include <QTimer>

namespace Ui {
class gamelobby;
}

class gamelobby : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamelobby(QWidget *parent = 0);
    ~gamelobby();
    Teamjoin *teampage;
signals :
    void startclicked();

private slots:

    void connecting_msg();

    void on_namebutton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void update();

private:
    Ui::gamelobby *ui;
    progressbar *progress;

    QTimer timer;
};

#endif // GAMELOBBY_H
