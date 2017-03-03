/********************************************************************************
** Form generated from reading UI file 'teamjoin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMJOIN_H
#define UI_TEAMJOIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teamjoin
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QListView *TeamB_listview;
    QSpacerItem *horizontalSpacer_6;
    QListView *NeutralTeam_listview;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *Message;
    QHBoxLayout *horizontalLayout;
    QPushButton *StartButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *chatbox;
    QSpacerItem *verticalSpacer;
    QListView *TeamA_listview;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *Teamjoin)
    {
        if (Teamjoin->objectName().isEmpty())
            Teamjoin->setObjectName(QStringLiteral("Teamjoin"));
        Teamjoin->resize(641, 630);
        Teamjoin->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(Teamjoin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(425, 358, 81, 32));
        label->setStyleSheet(QLatin1String("color: rgb(17, 0, 255);\n"
"background-color: rgb(232, 200, 29);"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(85, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        TeamB_listview = new QListView(centralwidget);
        TeamB_listview->setObjectName(QStringLiteral("TeamB_listview"));
        TeamB_listview->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ClosedHandCursor)));
        TeamB_listview->setAcceptDrops(true);
        TeamB_listview->setAutoFillBackground(true);
        TeamB_listview->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(198, 219, 159);\n"
""));
        TeamB_listview->setFrameShape(QFrame::WinPanel);
        TeamB_listview->setFrameShadow(QFrame::Sunken);
        TeamB_listview->setLineWidth(4);
        TeamB_listview->setMidLineWidth(1);
        TeamB_listview->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TeamB_listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TeamB_listview->setDragEnabled(true);
        TeamB_listview->setDragDropOverwriteMode(false);
        TeamB_listview->setDragDropMode(QAbstractItemView::DragDrop);
        TeamB_listview->setDefaultDropAction(Qt::MoveAction);
        TeamB_listview->setTextElideMode(Qt::ElideRight);

        gridLayout->addWidget(TeamB_listview, 2, 2, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(84, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        NeutralTeam_listview = new QListView(centralwidget);
        NeutralTeam_listview->setObjectName(QStringLiteral("NeutralTeam_listview"));
        NeutralTeam_listview->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ClosedHandCursor)));
        NeutralTeam_listview->setFocusPolicy(Qt::StrongFocus);
        NeutralTeam_listview->setAcceptDrops(true);
#ifndef QT_NO_ACCESSIBILITY
        NeutralTeam_listview->setAccessibleName(QStringLiteral(""));
#endif // QT_NO_ACCESSIBILITY
        NeutralTeam_listview->setAutoFillBackground(false);
        NeutralTeam_listview->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(198, 219, 159);"));
        NeutralTeam_listview->setLineWidth(4);
        NeutralTeam_listview->setMidLineWidth(1);
        NeutralTeam_listview->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        NeutralTeam_listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        NeutralTeam_listview->setDragEnabled(true);
        NeutralTeam_listview->setDragDropOverwriteMode(false);
        NeutralTeam_listview->setDragDropMode(QAbstractItemView::DragDrop);
        NeutralTeam_listview->setDefaultDropAction(Qt::MoveAction);
        NeutralTeam_listview->setTextElideMode(Qt::ElideRight);
        NeutralTeam_listview->setViewMode(QListView::ListMode);
        NeutralTeam_listview->setUniformItemSizes(true);

        gridLayout->addWidget(NeutralTeam_listview, 1, 0, 2, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(242, 99, 99);\n"
"background-color: rgb(222, 206, 94);"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(153, 145, 91);\n"
"color: rgb(0, 66, 255);"));

        horizontalLayout_2->addWidget(label_3);

        Message = new QLineEdit(centralwidget);
        Message->setObjectName(QStringLiteral("Message"));
        Message->setAutoFillBackground(false);
        Message->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(210, 32, 32);"));

        horizontalLayout_2->addWidget(Message);


        gridLayout->addLayout(horizontalLayout_2, 8, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setFocusPolicy(Qt::NoFocus);
        StartButton->setStyleSheet(QStringLiteral("background-color: rgb(199, 202, 221);"));
        StartButton->setAutoDefault(true);

        horizontalLayout->addWidget(StartButton);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(199, 202, 221);"));
        pushButton->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("font: 75 11pt \"Lucida Console\";\n"
"background-color: rgb(148, 185, 183);\n"
"border-color: rgb(0, 255, 25);"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 6, 0, 1, 3);

        chatbox = new QListWidget(centralwidget);
        chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->setAutoFillBackground(true);
        chatbox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 145);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"border-color: rgb(212, 22, 22);"));
        chatbox->setLineWidth(4);
        chatbox->setMidLineWidth(1);
        chatbox->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(chatbox, 7, 0, 1, 5);

        verticalSpacer = new QSpacerItem(310, 23, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 3, 1, 3, 4);

        TeamA_listview = new QListView(centralwidget);
        TeamA_listview->setObjectName(QStringLiteral("TeamA_listview"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TeamA_listview->sizePolicy().hasHeightForWidth());
        TeamA_listview->setSizePolicy(sizePolicy);
        TeamA_listview->setFocusPolicy(Qt::StrongFocus);
        TeamA_listview->setAcceptDrops(true);
        TeamA_listview->setAutoFillBackground(true);
        TeamA_listview->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(198, 219, 159);"));
        TeamA_listview->setFrameShape(QFrame::WinPanel);
        TeamA_listview->setLineWidth(4);
        TeamA_listview->setMidLineWidth(1);
        TeamA_listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TeamA_listview->setDragEnabled(true);
        TeamA_listview->setDragDropOverwriteMode(false);
        TeamA_listview->setDragDropMode(QAbstractItemView::DragDrop);
        TeamA_listview->setDefaultDropAction(Qt::MoveAction);
        TeamA_listview->setTextElideMode(Qt::ElideRight);

        gridLayout->addWidget(TeamA_listview, 1, 2, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 2, 1);

        Teamjoin->setCentralWidget(centralwidget);
        chatbox->raise();
        TeamA_listview->raise();
        label->raise();
        TeamB_listview->raise();
        NeutralTeam_listview->raise();
        label_2->raise();
        QWidget::setTabOrder(NeutralTeam_listview, TeamA_listview);
        QWidget::setTabOrder(TeamA_listview, TeamB_listview);

        retranslateUi(Teamjoin);
        QObject::connect(Message, SIGNAL(returnPressed()), Teamjoin, SLOT(update()));

        QMetaObject::connectSlotsByName(Teamjoin);
    } // setupUi

    void retranslateUi(QMainWindow *Teamjoin)
    {
        Teamjoin->setWindowTitle(QApplication::translate("Teamjoin", "MainWindow", 0));
        label->setText(QApplication::translate("Teamjoin", "<html><head/><body><p><span style=\" font-size:18pt;\">Team B</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        NeutralTeam_listview->setToolTip(QApplication::translate("Teamjoin", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Teamjoin", "<html><head/><body><p><span style=\" font-size:18pt;\">Team A</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Teamjoin", "Chat :", 0));
        Message->setInputMask(QString());
        StartButton->setText(QApplication::translate("Teamjoin", "Start Game", 0));
        pushButton->setText(QApplication::translate("Teamjoin", "ADD_AI", 0));
        label_4->setText(QApplication::translate("Teamjoin", "<html><head/><body><p><span style=\" font-size:24pt;\">Messages</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Teamjoin: public Ui_Teamjoin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMJOIN_H
