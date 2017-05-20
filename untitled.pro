#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T01:02:35
#
#-------------------------------------------------

QT       += core gui    \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Arrow.cpp \
    Castle.cpp \
    Knight.cpp \
    btn.cpp \
    Archer.cpp \
    Rogue.cpp \
    Sniper.cpp \
    BuildKnightIcon.cpp \
    BuildArcherIcon.cpp \
    BuildRogueIcon.cpp \
    BuildSniperIcon.cpp \
    gameover.cpp \
    Com_Archer.cpp \
    Com_Castle.cpp \
    Com_Knight.cpp \
    Com_Rogue.cpp \
    Com_Sniper.cpp

HEADERS  += \
    Game.h \
    Arrow.h \
    Castle.h \
    Knight.h \
    btn.h \
    Rogue.h \
    Archer.h \
    Sniper.h \
    BuildKnightIcon.h \
    BuildArcherIcon.h \
    BuildRogueIcon.h \
    BuildSniperIcon.h \
    gameover.h \
    Com_Castle.h \
    Com_Knight.h \
    Com_Rogue.h \
    Com_Sniper.h \
    Com_Archer.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

DISTFILES += \
    image/start.jpg \
    image/home2.jpg \
    image/home.jpg \
    image/battlemap2.jpg \
    image/castle_user.png \
    image/castle_com.png \
    image/battlemap.png \
    image/arrow.png
