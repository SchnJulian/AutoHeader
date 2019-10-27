// 
// Copyright (C) 2019 Julian Schnabel
// julian-schnabel@posteo.de www.github.com/SchnJulian
// 
// This file is part of AutoHeader.
// 
// AutoHeader must not be copied and/or distributed without the express
// permission of Julian Schnabel.
// 
// 27.10.2019


#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return QApplication::exec();
}
