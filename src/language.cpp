#include "language.h"

int Language::Language::getLanguageID() const { return languageID; }
void Language::Language::setLanguageID(int value) { languageID = value; }
Language::Language::Language() = default;
Language::Language::~Language() = default;
QStringList Language::Language::getSingleLine() const { return singleLine; }
void Language::Language::setSingleLine(const QStringList& value) {
  singleLine = value;
}
QStringList Language::Language::getMultiLine() const {
  return (!multiLine.isEmpty() ? multiLine : singleLine);
}
void Language::Language::setMultiLine(const QStringList& value) {
  multiLine = value;
}
