#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QDialog>

namespace Ui {
class gamemode;
}

class gamemode : public QDialog
{
    Q_OBJECT

public:
    explicit gamemode(QWidget *parent = 0);
    ~gamemode();

private slots:
    void on_timemode_clicked();

    void on_goalmode_clicked();

    void on_insanemode_clicked();

private:
    Ui::gamemode *ui;
};

#endif // GAMEMODE_H
