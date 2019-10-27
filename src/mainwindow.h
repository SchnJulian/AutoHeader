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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QClipboard>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QMimeDatabase>
#include <QMimeType>
#include <QStandardItemModel>
#include <string>
#include <utility>
#include "header.h"
#include "language.h"
#include "templates.h"
#include "userdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  // Error-codes for the results to show why a file could not be used
  enum STATE : int {
    GOOD = 0,
    READONLY = 1,
    WRITEONLY = 2,
    TYPEERR = 3,
    UNKNOWN = 4,
    FILEEXTENSION = 5
  };

  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 private slots:
#pragma region UI_events
  void on_selectButton_clicked();
  void on_fileEditor_textChanged();
  void on_templateComboBox_activated(int index);
  void on_fileListWidget_itemDoubleClicked(QListWidgetItem* item);
  void on_fileListWidget_itemSelectionChanged();
  void on_startButton_clicked();
  void on_safeModeCheckBox_stateChanged(int arg1);
  void on_forceSingleLine_stateChanged(int arg1);
#pragma endregion UI_events

  void deleteItem();
  void selectFiles();
  void clearFileEditor();
  void deleteAllItems();
  void copyHeader();
  void importTemplate();
  void saveToFile();
  void save();
  void createUser();
  void delegateDeleteHeader();
  void delegateDeleteHeaderSafeMode();

private:
  Ui::MainWindow* ui;
#pragma region Actions
  QAction* selectFilesAction{};
  QAction* deleteFilesAction{};
  QAction* deleteAllFilesAction{};
  QAction* clearFileEditorAction{};
  QAction* saveToFileAction{};
  QAction* importTemplateAction{};
  QAction* copyheaderAction{};
  QAction* saveAction{};
  QAction* createUserAction{};
  QAction* deleteHeaderAction{};
  QAction* deleteHeaderSafeModeAction{};
#pragma endregion Actions

#pragma region Menus
  QMenu* fileMenu{};
  QMenu* editMenu{};
  QMenu* deleteMenu{};
  QMenu* helpMenu{};  //! TODO
#pragma endregion Menus

#pragma region auxiliary - functions
  void setHeader(const QString& header);
  void initComboBox();
  void initLanguages();
  void initMenu();
  void initExtensions();
  void readFileList();
  void fillFileList(const QStringList& files);
  void selectLanguageFromIndex(int index);
  void readTemplate(const QString& path);
  bool checkMIME(const QString& path);  // Read the MIME-Type to determine
                                        // wether a file is a text file
  void printResultsToFile();
  std::pair<bool, Language::Language> readFileExtension(const QString& suffix);
  void warning();
  void enableUi();
  void disableUi();
  bool deleteHeader(int lineCount);
  bool deleteHeaderSafeMode(int lineCount);
#pragma endregion auxiliary - functions
  bool safeMode = false;
  QString commentHeader(
      const QString&,
      const Language::Language& language);  // Comment the header for
                                            // a specific language
  QString commentHeaderSingleLine(const Language::Language& language);
  QString commentHeaderMultiLine(const Language::Language& language);
  Language::Language language;  // Current language of the file being processed
  std::map<int, Language::Language> languages;
  std::multimap<QString, int> extensions;
  bool unsaved{};
  QString currentHeaderPath;
  QDir currentDirectory;
  QStringList fileNameList;
  std::vector<std::pair<QString, STATE>> status;
  Header header;
  bool processFiles();
  bool processFilesSafeMode();
};

#endif  // MAINWINDOW_H
