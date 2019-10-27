QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoHeader
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += \
        c++17 \
        sdk_no_version_check

ICON = logo.icns

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        header.cpp \
        language.cpp \
        userdialog.cpp
HEADERS += \
        mainwindow.h \
        header.h \
        templates.h \
        language.h \
        userdialog.h
FORMS += \
        mainwindow.ui \
        userdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    logo.icns
