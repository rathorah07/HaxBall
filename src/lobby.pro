#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T03:34:32
#
#-------------------------------------------------

QT       += core gui opengl
	
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lobby
TEMPLATE = app

CONFIG += c++11 warn_off
LIBS    += -lglut -lGL -lm -lglut -lc -lGLU -lpthread -lenet -lGLU -lsfml-audio
OBJECTS_DIR = ./obj
INCLUDEPATH = ./include
UI_DIR = ./intermediate
MOC_DIR = ./intermediate
RCC_DIR = ./intermediate

FORMS += \
    ui/game.ui \
    ui/gamelobby.ui \
    ui/gamemode.ui \
    ui/gamewindow.ui \
    ui/progressbar.ui \
    ui/teamjoin.ui

HEADERS += \
    include/AI.h \
    include/Ball.h \
    include/Collisions.h \
    include/connection.h \
    include/Constants.h \
    include/Detect_Goal.h \
    include/Display.h \
    include/enet_guest.h \
    include/enet_host.h \
    include/gamelobby.h \
    include/gamemode.h \
    include/Gamestate.h \
    include/gamewindow.h \
    include/global_data.h \
    include/glwidget.h \
    include/helperfunc.h \
    include/Interaction.h \
    include/mysignal.h \
    include/packetheader.h \
    include/peerdata.h \
    include/Player.h \
    include/position.h \
    include/Positions.h \
    include/progressbar.h \
    include/readpacket.h \
    include/States.h \
    include/teamjoin.h \
    include/variables.h \
    include/Vector.h \
    include/writepackets.h

SOURCES += \
    src/AI.cpp \
    src/Ball.cpp \
    src/Collisions.cpp \
    src/connection.cpp \
    src/Constants.cpp \
    src/Detect_Goal.cpp \
    src/Display.cpp \
    src/enet_guest.cpp \
    src/enet_host.cpp \
    src/gamelobby.cpp \
    src/gamemode.cpp \
    src/Gamestate.cpp \
    src/gamewindow.cpp \
    src/global_data.cpp \
    src/glwidget.cpp \
    src/helperfunc.cpp \
    src/Interaction.cpp \
    src/main.cpp \
    src/mysignal.cpp \
    src/peerdata.cpp \
    src/Player.cpp \
    src/progressbar.cpp \
    src/readpacket.cpp \
    src/States.cpp \
    src/teamjoin.cpp \
    src/variables.cpp \
    src/Vector.cpp \
    src/writepackets.cpp

RESOURCES += \
    assets/images.qrc\

DESTDIR = ./bin
