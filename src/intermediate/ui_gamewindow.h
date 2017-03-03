/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QLabel *clock;
    GlWidget *widget;
    QLabel *glabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *Message;
    QListWidget *chatbox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *showgoal;
    QLabel *label_4;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->setWindowModality(Qt::ApplicationModal);
        GameWindow->resize(1062, 700);
        GameWindow->setFocusPolicy(Qt::StrongFocus);
        GameWindow->setStyleSheet(QStringLiteral("background-color: rgb(156, 128, 128);"));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        clock = new QLabel(centralwidget);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(940, 0, 111, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clock->sizePolicy().hasHeightForWidth());
        clock->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        clock->setFont(font);
        clock->setStyleSheet(QLatin1String("border-color: rgb(46, 104, 128);\n"
"background-color: rgb(143, 179, 170);\n"
"color: rgb(82, 40, 37);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
""));
        clock->setFrameShape(QFrame::WinPanel);
        clock->setFrameShadow(QFrame::Sunken);
        clock->setTextFormat(Qt::RichText);
        clock->setAlignment(Qt::AlignCenter);
        widget = new GlWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 50, 1044, 431));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setFocusPolicy(Qt::StrongFocus);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(47, 35, 35);"));
        glabel = new QLabel(widget);
        glabel->setObjectName(QStringLiteral("glabel"));
        glabel->setGeometry(QRect(0, 0, 1062, 441));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(glabel->sizePolicy().hasHeightForWidth());
        glabel->setSizePolicy(sizePolicy2);
        glabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 670, 391, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(209, 95, 95);\n"
"color: rgb(213, 30, 30);"));

        horizontalLayout_2->addWidget(label_3);

        Message = new QLineEdit(layoutWidget);
        Message->setObjectName(QStringLiteral("Message"));
        Message->setAutoFillBackground(false);
        Message->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(Message);

        chatbox_2 = new QListWidget(centralwidget);
        chatbox_2->setObjectName(QStringLiteral("chatbox_2"));
        chatbox_2->setGeometry(QRect(260, 490, 561, 181));
        chatbox_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 145);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"border-color: rgb(212, 22, 22);"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(400, 0, 311, 43));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 38);"));

        horizontalLayout->addWidget(label);

        showgoal = new QLabel(layoutWidget1);
        showgoal->setObjectName(QStringLiteral("showgoal"));
        QFont font1;
        font1.setFamily(QStringLiteral("Century Schoolbook L"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        showgoal->setFont(font1);
        showgoal->setTextFormat(Qt::RichText);
        showgoal->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(showgoal);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(0, 1, 255);"));

        horizontalLayout->addWidget(label_4);

        GameWindow->setCentralWidget(centralwidget);
        widget->raise();
        clock->raise();
        layoutWidget->raise();
        chatbox_2->raise();
        layoutWidget->raise();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "MainWindow", 0));
        clock->setText(QApplication::translate("GameWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        glabel->setText(QString());
        label_3->setText(QApplication::translate("GameWindow", "Chat :", 0));
        Message->setInputMask(QString());
        label->setText(QString());
        showgoal->setText(QApplication::translate("GameWindow", "<html><head/><body><p align=\"center\">0 : 0</p></body></html>", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
