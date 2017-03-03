#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QMainWindow>

namespace Ui {
class progressbar;
}

class progressbar : public QMainWindow
{
    Q_OBJECT

public:
    explicit progressbar(QWidget *parent = 0);
    ~progressbar();

private:
    Ui::progressbar *ui;
};

#endif // PROGRESSBAR_H
