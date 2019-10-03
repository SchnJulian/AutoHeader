#include "userdialog.h"
#include <QDebug>
#include "ui_userdialog.h"

UserDialog::UserDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDialog) {
  ui->setupUi(this);
  readUser();
  ui->fullNameEdit->setText(user.fullName);
  ui->emailEdit->setText(user.email);
  ui->OrganizationEdit->setText(user.organization);
  ui->githubEdit->setText(user.github);
  ui->LicenseEdit->setText(user.license);
}

UserDialog::~UserDialog() { delete ui; }

void UserDialog::readUser(const QString &path) {
  QFile file(path);
  if (file.open(QIODevice::ReadOnly)) {
    QStringList wordList;
    QByteArray line = file.readLine();
    while (!file.atEnd()) {
      line = file.readLine();
      wordList.append(line.split(',').at(1));
    }
    try {
      user.fullName = wordList.at(0).simplified();
      user.email = wordList.at(1).simplified();
      user.organization = wordList.at(2).simplified();
      user.github = wordList.at(3).simplified();
      user.license = wordList.at(4).simplified();
    } catch (...) {
    }

    file.close();
  }
}

void UserDialog::createFile(const QString &path) {
  QFile file(path);
  if (file.open(QIODevice::WriteOnly)) {
    QTextStream out(&file);
    out << "tag"
        << ","
        << "value"
        << "\n"
        << "fullName"
        << "," << user.fullName << "\n"
        << "email"
        << "," << user.email << "\n"
        << "organization"
        << "," << user.organization << "\n"
        << "github"
        << "," << user.github << "\n"
        << "license"
        << "," << user.license;
  }
  file.close();
}

void UserDialog::on_fullNameEdit_textChanged(const QString &arg1) {
  user.fullName = arg1;
}

void UserDialog::on_emailEdit_textChanged(const QString &arg1) {
  user.email = arg1;
}

void UserDialog::on_OrganizationEdit_textChanged(const QString &arg1) {
  user.organization = arg1;
}

void UserDialog::on_githubEdit_textChanged(const QString &arg1) {
  user.github = arg1;
}

void UserDialog::on_LicenseEdit_textChanged(const QString &arg1) {
  user.license = arg1;
}
void UserDialog::on_buttonBox_accepted() { createFile(); }
