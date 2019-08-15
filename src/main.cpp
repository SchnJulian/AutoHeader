/* 
Copyright (C) 2019 Julian Schnabel - julian schnabel@outlook.com

This file is part of AutoHeader. (https://github.com/SchnJulian/AutoHeader)

AutoHeader is licensed under GPL v. 3. See LICENSE for further information. */

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return QApplication::exec();
}
