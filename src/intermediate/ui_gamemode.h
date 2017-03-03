/********************************************************************************
** Form generated from reading UI file 'gamemode.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODE_H
#define UI_GAMEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gamemode
{
public:
    QPushButton *timemode;
    QPushButton *goalmode;
    QPushButton *insanemode;

    void setupUi(QDialog *gamemode)
    {
        if (gamemode->objectName().isEmpty())
            gamemode->setObjectName(QStringLiteral("gamemode"));
        gamemode->resize(400, 279);
        gamemode->setStyleSheet(QStringLiteral("background-color: rgb(175, 165, 165);"));
        timemode = new QPushButton(gamemode);
        timemode->setObjectName(QStringLiteral("timemode"));
        timemode->setGeometry(QRect(140, 10, 131, 61));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timemode->sizePolicy().hasHeightForWidth());
        timemode->setSizePolicy(sizePolicy);
        timemode->setStyleSheet(QStringLiteral("background-color: rgb(27, 118, 121);"));
        goalmode = new QPushButton(gamemode);
        goalmode->setObjectName(QStringLiteral("goalmode"));
        goalmode->setGeometry(QRect(140, 100, 131, 61));
        insanemode = new QPushButton(gamemode);
        insanemode->setObjectName(QStringLiteral("insanemode"));
        insanemode->setGeometry(QRect(140, 200, 131, 61));

        retranslateUi(gamemode);

        QMetaObject::connectSlotsByName(gamemode);
    } // setupUi

    void retranslateUi(QDialog *gamemode)
    {
        gamemode->setWindowTitle(QApplication::translate("gamemode", "Dialog", 0));
        timemode->setText(QApplication::translate("gamemode", "Timemode", 0));
        goalmode->setText(QApplication::translate("gamemode", "Goalmode", 0));
        insanemode->setText(QApplication::translate("gamemode", "InsaneMode", 0));
    } // retranslateUi

};

namespace Ui {
    class gamemode: public Ui_gamemode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODE_H
