TEMPLATE = app

QT += core gui widgets
QT += widgets

CONFIG += c++17
CONFIG -= console
CONFIG -= app_bundle

SOURCES += \
    agua.cpp \
    cartaelemento.cpp \
    elemento.cpp \
    elementomixto.cpp \
    fabricaelementos.cpp \
    fuego.cpp \
    ia.cpp \
    iaaleatoria.cpp \
    iaestrategica.cpp \
    iajugador.cpp \
    inicio.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    par.cpp \
    partida.cpp \
    superia.cpp \
    tabladanio.cpp \
    tierra.cpp \
    tipoelemento.cpp

HEADERS += \
    agua.h \
    cartaelemento.h \
    elemento.h \
    elementomixto.h \
    fabricaelementos.h \
    fuego.h \
    ia.h \
    iaaleatoria.h \
    iaestrategica.h \
    iajugador.h \
    inicio.h \
    jugador.h \
    mainwindow.h \
    par.h \
    partida.h \
    superia.h \
    tabladanio.h \
    tierra.h \
    tipoelemento.h

FORMS += \
    inicio.ui \
    mainwindow.ui
