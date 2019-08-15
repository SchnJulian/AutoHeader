/* 
Copyright (C) 2019 Julian Schnabel - julian schnabel@outlook.com

This file is part of AutoHeader. (https://github.com/SchnJulian/AutoHeader)

AutoHeader is licensed under GPL v. 3. See LICENSE for further information. */

#include "resultsview.h"
#include "ui_resultsview.h"

ResultsView::ResultsView(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ResultsView)
{
  ui->setupUi(this);
}

ResultsView::~ResultsView()
{
  delete ui;
}

