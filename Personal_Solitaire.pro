TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    card.cpp \
    deck.cpp \
    queue.cpp \
    game.cpp

HEADERS += \
    card.h \
    deck.h \
    game.h
