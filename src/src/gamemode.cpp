#include "gamemode.h"
#include "ui_gamemode.h"
#include "variables.h"
#include "helperfunc.h"
#include "QMessageBox"
#include "QInputDialog"

gamemode::gamemode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamemode)
{
    ui->setupUi(this);
}

gamemode::~gamemode()
{
    delete ui;
}

void gamemode::on_timemode_clicked()
{
    QInputDialog ret;
    ret.setLabelText("MAX TIME(min)");
    ret.exec();
    QString time = ret.textValue();

    if(time == "\0" || time == "0")
    {
        QMessageBox::information(this,"error","time limit not set");
    }

    else
    {
        mincounter = string_to_int(time.toStdString());
    }

}



void gamemode::on_goalmode_clicked()
{
    QInputDialog ret;
    ret.setLabelText("MAX TIME(min)");
    ret.exec();
    QString time = ret.textValue();

    if(time == "\0" || time == "0")
    {
        QMessageBox::information(this,"error","Not a valid number");
    }

    else
    {
        maxgoal = string_to_int(time.toStdString());
    }
}

void gamemode::on_insanemode_clicked()
{
    on_timemode_clicked();
    on_goalmode_clicked();
}
