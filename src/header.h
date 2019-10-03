/*
Copyright (C) 2019 Julian Schnabel - julian schnabel@outlook.com

This file is part of AutoHeader. (https://github.com/SchnJulian/AutoHeader)

AutoHeader is licensed under GPL v. 3. See LICENSE for further information. */

#ifndef HEADER_H
#define HEADER_H

#include <QDate>
#include <QDebug>
#include <QString>
#include "userdialog.h"
// Class to combine the raw header (QString) and some additional info like
// wether it is a multi-line-header or not and if the autodetect system should
// be used
class Header {
 public:
  Header();
  ~Header();
  bool multiLine{};        // Multi-line-comment or single-line-comment
  bool autoDetect = true;  // AutoDetect language
  bool forceSingleLine{};

  [[nodiscard]] QString getContent() const;
  QString getParsedContent();
  void setContent(const QString& value);
  void parse();
  void readUser(const QString& path = "/usr/local/etc/ac_usr.csv");

 private:
  UserDialog::User user;
  QString content;  // Actual text of the header
};
#endif  // HEADER_H
