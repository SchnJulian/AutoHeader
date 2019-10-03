#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QFile>
#include <QStringList>
#include <QTextStream>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog {
  Q_OBJECT

 public:
  class User {
   public:
    QString fullName, email, github, organization, license;
  };
  User user;
  explicit UserDialog(QWidget *parent = nullptr);
  ~UserDialog() override;

 private slots:
  void on_LicenseEdit_textChanged(const QString &arg1);

  void on_fullNameEdit_textChanged(const QString &arg1);

  void on_emailEdit_textChanged(const QString &arg1);

  void on_OrganizationEdit_textChanged(const QString &arg1);

  void on_githubEdit_textChanged(const QString &arg1);

  void on_buttonBox_accepted();

 private:
  void readUser(const QString& path = "/usr/local/etc/ac_usr.csv");
  Ui::UserDialog *ui;
  void createFile(const QString& path = "/usr/local/etc/ac_usr.csv");
};

#endif  // USERDIALOG_H
