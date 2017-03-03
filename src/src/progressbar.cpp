#include "progressbar.h"
#include "ui_progressbar.h"

progressbar::progressbar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::progressbar)
{
    ui->setupUi(this);
}

progressbar::~progressbar()
{
    delete ui;
}
