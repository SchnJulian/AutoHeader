/* 
Copyright (C) 2019 Julian Schnabel - julian schnabel@outlook.com

This file is part of AutoHeader. (https://github.com/SchnJulian/AutoHeader)

AutoHeader is licensed under GPL v. 3. See LICENSE for further information. */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QStringList>
#include <map>

namespace Language {
//  Class to store comment-charater-set for different languages e.g. "//" in C
//  and "#" in Python
class Language {
 private:
  QStringList singleLine;  // Character(s) that indicate a single-line-comment
  QStringList multiLine;   // Characters that indicate a multi-line-comment
  int languageID{};  // Language ID (see mainwindow.cpp -> setupLanguages) user
                     // to select the correct Language when manually choosing
                     // one through the comboBox

 public:
  Language();
  ~Language();
  QStringList getSingleLine() const;
  void setSingleLine(const QStringList& value);
  QStringList getMultiLine() const;
  void setMultiLine(const QStringList& value);
  int getLanguageID() const;
  void setLanguageID(int value);
};
}  // namespace Language

#endif  // LANGUAGE_H
