/********************************************************************************
** Form generated from reading UI file 'progressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_H
#define UI_PROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_progressbar
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QProgressBar *bar1;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *progressbar)
    {
        if (progressbar->objectName().isEmpty())
            progressbar->setObjectName(QStringLiteral("progressbar"));
        progressbar->resize(455, 263);
        centralwidget = new QWidget(progressbar);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        bar1 = new QProgressBar(centralwidget);
        bar1->setObjectName(QStringLiteral("bar1"));
        bar1->setAutoFillBackground(false);
        bar1->setMaximum(0);
        bar1->setValue(-1);
        bar1->setInvertedAppearance(true);

        gridLayout->addWidget(bar1, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        progressbar->setCentralWidget(centralwidget);
        menubar = new QMenuBar(progressbar);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 455, 23));
        progressbar->setMenuBar(menubar);
        statusbar = new QStatusBar(progressbar);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        progressbar->setStatusBar(statusbar);

        retranslateUi(progressbar);

        QMetaObject::connectSlotsByName(progressbar);
    } // setupUi

    void retranslateUi(QMainWindow *progressbar)
    {
        progressbar->setWindowTitle(QApplication::translate("progressbar", "MainWindow", 0));
        label->setText(QApplication::translate("progressbar", "Connecting to Server..", 0));
    } // retranslateUi

};

namespace Ui {
    class progressbar: public Ui_progressbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_H
