// 
// Copyright (C) 2019 Julian Schnabel
// julian-schnabel@posteo.de github.com/SchnJulian
// 
// This file is part of AutoHeader.
// 
// AutoHeader can not be copied and/or distributed without the express
// permission of Julian Schnabel


#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QStringList>
#include <map>

namespace Language {
//  Class to store comment-charater-set for different languages e.g. "//" in C
//  and "#" in Python
class Language {
private:
QStringList singleLine;    // Character(s) that indicate a single-line-comment
QStringList multiLine;     // Characters that indicate a multi-line-comment
int languageID{};    // Language ID (see mainwindow.cpp -> setupLanguages) user
                     // to select the correct Language when manually choosing
                     // one through the comboBox

public:
Language();
~Language();
[[nodiscard]] QStringList getSingleLine() const;
void setSingleLine(const QStringList& value);
[[nodiscard]] QStringList getMultiLine() const;
void setMultiLine(const QStringList& value);
[[nodiscard]] int getLanguageID() const;
void setLanguageID(int value);
};
}  // namespace Language

#endif  // LANGUAGE_H
