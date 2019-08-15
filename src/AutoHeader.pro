QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoHeader
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++17
ICON = logo.icns

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        header.cpp \
        language.cpp
HEADERS += \
        mainwindow.h \
        header.h \
        templates.h \
        language.h
FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    logo.icns
