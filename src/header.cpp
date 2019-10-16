#include "header.h"

Header::Header() = default;
Header::~Header() = default;
Header::Header(const Header& old_obj) {
  this->content = old_obj.content;
  this->autoDetect = old_obj.autoDetect;
  this->forceSingleLine = old_obj.forceSingleLine;
  this->user = old_obj.user;
  this->multiLine = old_obj.multiLine;
}
QString Header::getContent() const { return content; }
QString Header::getParsedContent() {
  this->parse();
  return content;
}
void Header::setContent(const QString& value) { content = value; }
void Header::parse() {
  // Insert user data
  // Insert user name
  content.replace("<name>", user.fullName.toUtf8(), Qt::CaseInsensitive);
  // Insert email address
  content.replace("<email>", user.email.toUtf8(), Qt::CaseInsensitive);
  // Insert organization name
  content.replace("<organization>", user.organization.toUtf8(),
                  Qt::CaseInsensitive);
  // Inser github name/link
  content.replace("<github>", user.github.toUtf8(), Qt::CaseInsensitive);
  // Insert license name
  content.replace("<license>", user.license.toUtf8(), Qt::CaseInsensitive);
  // Insert date
  content.replace("<date>", QDate::currentDate().toString("dd.MM.yyyy"),
                  Qt::CaseInsensitive);
  // Insert date MM/dd/yyyy
  content.replace("<usdate>", QDate::currentDate().toString("MM/dd/yyyy"),
                  Qt::CaseInsensitive);
  // Insert year
  content.replace("<year>", QDate::currentDate().toString("yyyy"),
                  Qt::CaseInsensitive);
}
void Header::readUser(const QString& path) {
  QFile file(path);
  if (file.open(QIODevice::ReadOnly)) {
    QStringList wordList;
    QByteArray line = file.readLine();
    while (!file.atEnd()) {
      line = file.readLine();
      wordList.append(line.split(',').at(1));
    }
    user.fullName = wordList.at(0).simplified();
    user.email = wordList.at(1).simplified();
    user.organization = wordList.at(2).simplified();
    user.github = wordList.at(3).simplified();
    user.license = wordList.at(4).simplified();
    file.close();
  }
}
