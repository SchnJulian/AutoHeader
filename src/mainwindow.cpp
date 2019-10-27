#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  header.autoDetect = true;
  initMenu();
  initComboBox();
  initLanguages();
  initExtensions();
  warning();
}
MainWindow::~MainWindow() { delete ui; }
void MainWindow::initComboBox() {
  auto* model =
      qobject_cast<QStandardItemModel*>(ui->templateComboBox->model());
  QModelIndex firstIndex = model->index(0, ui->templateComboBox->modelColumn(),
                                        ui->templateComboBox->rootModelIndex());
  QStandardItem* firstItem = model->itemFromIndex(firstIndex);

  firstItem->setSelectable(false);
}
///
/// \brief Create langugage objects with the corresponding comment-characters.
///
void MainWindow::initLanguages() {
  // Ada
  Language::Language Ada;
  Ada.setSingleLine(QStringList{"--"});
  Ada.setLanguageID(1);
  // AppleScript
  Language::Language AppleScript;
  AppleScript.setSingleLine(QStringList{"(*", "*)"});
  AppleScript.setLanguageID(2);
  // C
  Language::Language C;
  C.setSingleLine(QStringList{"//"});
  C.setMultiLine(QStringList{"/*", "*/"});
  C.setLanguageID(4);
  // C++
  Language::Language CPP;
  CPP.setSingleLine(QStringList{"//"});
  CPP.setMultiLine(QStringList{"/*", "*/"});
  CPP.setLanguageID(5);
  // C#
  Language::Language CSharp;
  CSharp.setSingleLine(QStringList{"//"});
  CSharp.setMultiLine(QStringList{"/*", "*/"});
  CSharp.setLanguageID(6);
  // ColdFusion
  Language::Language ColdFusion;
  ColdFusion.setSingleLine(QStringList{"<!---", "--->"});
  ColdFusion.setLanguageID(7);
  // Fortran IV
  Language::Language Fortran_IV;
  Fortran_IV.setSingleLine(QStringList{"C"});
  Fortran_IV.setLanguageID(8);
  // Haskell
  Language::Language Haskell;
  Haskell.setSingleLine(QStringList{"--"});
  Haskell.setMultiLine(QStringList{"{-", "-}"});
  Haskell.setLanguageID(9);
  // Java
  Language::Language Java;
  Java.setSingleLine(QStringList{"//"});
  Java.setMultiLine(QStringList{"/*", "*/"});
  Java.setLanguageID(10);
  // JavaScript
  Language::Language JavaScript;
  JavaScript.setSingleLine(QStringList{"//"});
  JavaScript.setMultiLine(QStringList{"/*", "/*"});
  JavaScript.setLanguageID(11);
  // Lua
  Language::Language Lua;
  Lua.setSingleLine(QStringList{"--"});
  Lua.setMultiLine(QStringList{"--[[", "]]"});
  Lua.setLanguageID(12);
  // MATLAB
  Language::Language MATLAB;
  MATLAB.setMultiLine(QStringList{"%"});
  MATLAB.setLanguageID(13);
  // Pascal
  Language::Language Pascal;
  Pascal.setSingleLine(QStringList{"(*", "*)"});
  Pascal.setLanguageID(14);
  // Perl
  Language::Language Perl;
  Perl.setSingleLine(QStringList{"#"});
  Perl.setLanguageID(15);
  // PHP
  Language::Language PHP;
  PHP.setSingleLine(QStringList{"//"});
  PHP.setMultiLine(QStringList{"/*", "*/"});
  PHP.setLanguageID(16);
  // Powershell
  Language::Language Powershell;
  Powershell.setSingleLine(QStringList{"#"});
  Powershell.setMultiLine(QStringList{"<#", "#>"});
  Powershell.setLanguageID(17);
  // Python
  Language::Language Python;
  Python.setSingleLine(QStringList{"#"});
  Python.setLanguageID(18);
  // Ruby
  Language::Language Ruby;
  Ruby.setSingleLine(QStringList{"#"});
  Ruby.setMultiLine(QStringList{"=begin", "=end"});
  Ruby.setLanguageID(19);
  // SQL
  Language::Language SQL;
  SQL.setSingleLine(QStringList{"--"});
  SQL.setLanguageID(20);
  // Swift
  Language::Language Swift;
  Swift.setSingleLine(QStringList{"//"});
  Swift.setMultiLine(QStringList{"/*", "*/"});
  Swift.setLanguageID(21);
  // XML
  Language::Language XML;
  XML.setSingleLine(QStringList{"<!--", "-->"});
  XML.setLanguageID(22);
  // HTML
  Language::Language HTML;
  HTML.setSingleLine(QStringList{"<!--", "-->"});
  HTML.setLanguageID(23);
  // DUMMY
  Language::Language DUMMY;
  DUMMY.setLanguageID(0);
  languages.insert(std::make_pair(Ada.getLanguageID(), Ada));
  languages.insert(std::make_pair(AppleScript.getLanguageID(), AppleScript));
  languages.insert(std::make_pair(C.getLanguageID(), C));
  languages.insert(std::make_pair(CPP.getLanguageID(), CPP));
  languages.insert(std::make_pair(CSharp.getLanguageID(), CSharp));
  languages.insert(std::make_pair(ColdFusion.getLanguageID(), ColdFusion));
  languages.insert(std::make_pair(Fortran_IV.getLanguageID(), Fortran_IV));
  languages.insert(std::make_pair(Haskell.getLanguageID(), Haskell));
  languages.insert(std::make_pair(Java.getLanguageID(), Java));
  languages.insert(std::make_pair(JavaScript.getLanguageID(), JavaScript));
  languages.insert(std::make_pair(Lua.getLanguageID(), Lua));
  languages.insert(std::make_pair(MATLAB.getLanguageID(), MATLAB));
  languages.insert(std::make_pair(Pascal.getLanguageID(), Pascal));
  languages.insert(std::make_pair(Perl.getLanguageID(), Perl));
  languages.insert(std::make_pair(PHP.getLanguageID(), PHP));
  languages.insert(std::make_pair(Powershell.getLanguageID(), Powershell));
  languages.insert(std::make_pair(Python.getLanguageID(), Python));
  languages.insert(std::make_pair(Ruby.getLanguageID(), Ruby));
  languages.insert(std::make_pair(SQL.getLanguageID(), SQL));
  languages.insert(std::make_pair(Swift.getLanguageID(), Swift));
  languages.insert(std::make_pair(XML.getLanguageID(), XML));
  languages.insert(std::make_pair(HTML.getLanguageID(), HTML));
  languages.insert(std::make_pair(DUMMY.getLanguageID(), DUMMY));
}
///
/// \brief Add file-extensions to map.
///
void MainWindow::initExtensions() {
  extensions.insert(std::make_pair("ADA", 1));
  extensions.insert(std::make_pair("ADS", 1));
  extensions.insert(std::make_pair("CPT", 2));
  extensions.insert(std::make_pair("CPTD", 2));
  extensions.insert(std::make_pair("APPLESCRIPT", 2));
  extensions.insert(std::make_pair("C", 4));
  extensions.insert(std::make_pair("H", 4));
  extensions.insert(std::make_pair("CC", 5));
  extensions.insert(std::make_pair("HPP", 5));
  extensions.insert(std::make_pair("CXX", 5));
  extensions.insert(std::make_pair("H", 5));
  extensions.insert(std::make_pair("HPP", 5));
  extensions.insert(std::make_pair("CPP", 5));
  extensions.insert(std::make_pair("HXX", 5));
  extensions.insert(std::make_pair("CS", 6));
  extensions.insert(std::make_pair("CFM", 7));
  extensions.insert(std::make_pair("CFC", 7));
  extensions.insert(std::make_pair("F", 8));
  extensions.insert(std::make_pair("FOR", 8));
  extensions.insert(std::make_pair("F90", 8));
  extensions.insert(std::make_pair("HS", 9));
  extensions.insert(std::make_pair("LHS", 9));
  extensions.insert(std::make_pair("JAVA", 10));
  extensions.insert(std::make_pair("JS", 11));
  extensions.insert(std::make_pair("MJS", 11));
  extensions.insert(std::make_pair("LUA", 12));
  extensions.insert(std::make_pair("M", 13));
  extensions.insert(std::make_pair("PP", 14));
  extensions.insert(std::make_pair("PAS", 14));
  extensions.insert(std::make_pair("PL", 15));
  extensions.insert(std::make_pair("PM", 15));
  extensions.insert(std::make_pair("XS", 15));
  extensions.insert(std::make_pair("T", 15));
  extensions.insert(std::make_pair("POD", 15));
  extensions.insert(std::make_pair("PHP", 16));
  extensions.insert(std::make_pair("PHTML", 16));
  extensions.insert(std::make_pair("PHP3", 16));
  extensions.insert(std::make_pair("PHP4", 16));
  extensions.insert(std::make_pair("PHP5", 16));
  extensions.insert(std::make_pair("PHP7", 16));
  extensions.insert(std::make_pair("PHPS", 16));
  extensions.insert(std::make_pair("PHP_S", 16));  // php-stophp_s
  extensions.insert(std::make_pair("PHT", 16));
  extensions.insert(std::make_pair("PHAR", 16));
  extensions.insert(std::make_pair("PS1", 17));
  extensions.insert(std::make_pair("PY", 18));
  extensions.insert(std::make_pair("YC", 18));
  extensions.insert(std::make_pair("PYD", 18));
  extensions.insert(std::make_pair("PYO", 18));
  extensions.insert(std::make_pair("PYW", 18));
  extensions.insert(std::make_pair("PYZ", 18));
  extensions.insert(std::make_pair("RB", 19));
  extensions.insert(std::make_pair("SQL", 20));
  extensions.insert(std::make_pair("SWIFT", 21));
  extensions.insert(std::make_pair("XML", 22));
  extensions.insert(std::make_pair("HTML", 23));
}

///
/// \brief Set up the top-bar menu
///
void MainWindow::initMenu() {
  selectFilesAction = new QAction(tr("&Select files"), this);
  selectFilesAction->setShortcuts(QKeySequence::Open);
  selectFilesAction->setStatusTip(tr("Create a new file"));
  connect(selectFilesAction, &QAction::triggered, this,
          &MainWindow::selectFiles);

  deleteFilesAction = new QAction(tr("&Remove selected files"), this);
  deleteFilesAction->setShortcuts(QKeySequence::Delete);
  deleteFilesAction->setStatusTip(tr("Remove selected files"));
  connect(deleteFilesAction, &QAction::triggered, this,
          &MainWindow::deleteItem);

  deleteAllFilesAction = new QAction(tr("&Remove files"), this);
  deleteAllFilesAction->setStatusTip(tr("Remove all files"));
  connect(deleteAllFilesAction, &QAction::triggered, this,
          &MainWindow::deleteAllItems);

  clearFileEditorAction = new QAction(tr("&Clear editor"), this);
  clearFileEditorAction->setStatusTip(
      tr("Remove the text from the header editor"));
  connect(clearFileEditorAction, &QAction::triggered, this,
          &MainWindow::clearFileEditor);

  copyheaderAction = new QAction(tr("&Copy header"), this);
  copyheaderAction->setStatusTip(tr("Save the header in the clipboard"));
  copyheaderAction->setShortcut(QKeySequence::Copy);
  connect(copyheaderAction, &QAction::triggered, this, &MainWindow::copyHeader);

  importTemplateAction = new QAction(tr("&Import header"), this);
  importTemplateAction->setStatusTip(tr("Import custom header"));
  importTemplateAction->setShortcut(Qt::CTRL + Qt::Key_I);
  connect(importTemplateAction, &QAction::triggered, this,
          &MainWindow::importTemplate);

  saveToFileAction = new QAction(tr("&Save as"), this);
  saveToFileAction->setStatusTip(tr("Save header to file"));
  saveToFileAction->setShortcut(QKeySequence::SaveAs);
  connect(saveToFileAction, &QAction::triggered, this, &MainWindow::saveToFile);

  saveAction = new QAction(tr("&Save"), this);
  saveAction->setStatusTip(tr("Save header"));
  saveAction->setShortcut(QKeySequence::Save);
  connect(saveAction, &QAction::triggered, this, &MainWindow::save);
  saveAction->setEnabled(false);

  createUserAction = new QAction(tr("&Create user"), this);
  createUserAction->setStatusTip(tr("Create user file for faster work"));
  connect(createUserAction, &QAction::triggered, this, &MainWindow::createUser);
  createUserAction->setEnabled(true);

  fileMenu = menuBar()->addMenu(tr("File"));
  fileMenu->addAction(selectFilesAction);
  fileMenu->addSeparator();
  deleteMenu = fileMenu->addMenu(tr("Remove files"));
  deleteMenu->addAction(deleteFilesAction);
  deleteMenu->addAction(deleteAllFilesAction);
  fileMenu->addSeparator();
  fileMenu->addAction(saveAction);
  fileMenu->addAction(saveToFileAction);

  editMenu = menuBar()->addMenu(tr("Editor"));
  editMenu->addAction(copyheaderAction);
  editMenu->addAction(clearFileEditorAction);
  editMenu->addSeparator();
  editMenu->addAction(importTemplateAction);

  helpMenu = menuBar()->addMenu(tr("Help"));
  helpMenu->addAction(createUserAction);
}

QString MainWindow::commentHeader(const QString& header,
                                  const Language::Language& language) {
  if (this->header.forceSingleLine) {
    return commentHeaderSingleLine(language);
  }
  if (header.count("\n") >= 1 && language.getMultiLine().length() == 2) {
    return commentHeaderMultiLine(language);
  }
  return commentHeaderSingleLine(language);
}

QString MainWindow::commentHeaderSingleLine(
    const Language::Language& language) {
  QString temp = header.getParsedContent();
  QString line;
  QString final;
  QTextStream stream(&temp);
  if (language.getSingleLine().length() > 1) {
    temp.insert(0, language.getSingleLine()[0] + " ");
    temp.append(" " + language.getSingleLine()[1]);
    final = temp;
  } else {
    while (stream.readLineInto(&line)) {
      line.insert(0, language.getSingleLine()[0] + " ");
      final.append(line);
      final.append("\n");
    }
  }
  return final;
}
QString MainWindow::commentHeaderMultiLine(const Language::Language& language) {
  QString temp = header.getParsedContent();
  temp.insert(0, language.getMultiLine()[0] + " ");
  temp.append(" " + language.getMultiLine()[1]);
  return temp;
}
void MainWindow::saveToFile() {
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save Header"), "", tr("Text file(*.txt);;All Files (*)"));
  if (fileName.isEmpty()) return;
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::information(this, tr("Unable to open file"),
                             file.errorString());
    return;
  }
  QDataStream out(&file);
  out.setVersion(QDataStream::Qt_5_12);
  out << header.getContent();
  unsaved = false;
  currentHeaderPath = fileName;
  saveAction->setEnabled(true);
}
///
/// \brief Save the custom header to a file.
///
void MainWindow::save() {
  QFile file(currentHeaderPath);
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::information(this, tr("Unable to open file"),
                             file.errorString());
    return;
  }
  QDataStream out(&file);
  out.setVersion(QDataStream::Qt_5_12);
  out << header.getContent();
  unsaved = false;
}

void MainWindow::createUser() {
  auto* u = new UserDialog;
  u->show();
}

void MainWindow::copyHeader() {
  QClipboard* clipboard = QApplication::clipboard();
  clipboard->setText(ui->fileEditor->toPlainText());
}
void MainWindow::selectFiles() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  QDir directory(dir);
  currentDirectory.setPath(directory.absolutePath());
  QStringList files = directory.entryList(QStringList{"*.*"}, QDir::Files);
  fileNameList = files;
  if (!fileNameList.empty() && !header.getContent().isEmpty()) {
    ui->startButton->setEnabled(true);
  }
  fillFileList(files);
}
void MainWindow::importTemplate() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open template"), "/home", tr("Text Files (*.txt *.rtf)"));
  readTemplate(fileName);
}
void MainWindow::deleteAllItems() { ui->fileListWidget->clear(); }
void MainWindow::deleteItem() {
  QList<QListWidgetItem*> items = ui->fileListWidget->selectedItems();
  foreach (QListWidgetItem* item, items) {
    delete ui->fileListWidget->takeItem(ui->fileListWidget->row(item));
  }
  readFileList();
}
void MainWindow::clearFileEditor() { ui->fileEditor->clear(); }
void MainWindow::on_selectButton_clicked() { selectFiles(); }
void MainWindow::fillFileList(const QStringList& files) {
  foreach (QString f, files) { ui->fileListWidget->addItem(f); }
}
void MainWindow::readFileList() {
  fileNameList.clear();
  for (int i = 0; i < ui->fileListWidget->count(); ++i) {
    fileNameList.append(ui->fileListWidget->item(i)->text());
  }
}
void MainWindow::on_fileEditor_textChanged() {
  unsaved = true;
  if (ui->fileEditor->toPlainText().length() >= 1) {
    if (!fileNameList.empty()) {
      ui->startButton->setEnabled(true);
    }
    header.setContent(ui->fileEditor->toPlainText());
  } else {
    ui->fileEditor->setEnabled(true);
    ui->startButton->setEnabled(false);
  }
}
// Load template header and fill the fileEditor to make changes
void MainWindow::readTemplate(const QString& path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
  QTextStream in(&file);
  ui->fileEditor->clear();
  while (!in.atEnd()) {
    QString line = in.readLine();
    ui->fileEditor->appendPlainText(line);
  }
}
///
/// \brief Sets the conent of the header-editor.
/// \param header
///
void MainWindow::setHeader(const QString& header) {
  this->header.setContent(header);
  ui->fileEditor->clear();
  ui->fileEditor->setPlainText(this->header.getContent());
}
///
/// \brief Load the selected header.
///
void MainWindow::on_templateComboBox_activated(int index) {
  switch (index) {
    case 1:
      setHeader(STANDARD_HEADER);
      break;
    case 2:
      setHeader(STANDART_HEADER_ALT);
      break;
    case 3:
      setHeader(SEELICENSE);
      break;
    case 4:
      importTemplate();
      break;
    default:
      break;
  }
}
///
/// \brief Delete the clicked item.
/// \param item
///
void MainWindow::on_fileListWidget_itemDoubleClicked(QListWidgetItem* item) {
  delete item;
}
///
/// \brief Refresh the file-list.
///
void MainWindow::on_fileListWidget_itemSelectionChanged() { readFileList(); }
///
/// \brief Prepend the header and save the new files
/// First the files are checked for compatibility. Then the current content of
/// the files to be processed is stored in a buffer. The header is prepended
/// to an new file and the old content will be appended to the new file.
///
bool MainWindow::processFiles() {
  QString temp;
  std::pair<bool, Language::Language> l;
  for (int i = 0; i < fileNameList.length(); i++) {
    temp = currentDirectory.absolutePath() + "/" + fileNameList[i];
    QFileInfo fi(temp);
    l = readFileExtension(fi.completeSuffix().toUpper());
    if (l.first) {
      QFile file(temp);
      if (!file.open(QIODevice::ReadOnly |
                     QIODevice::Text)) {  // Check if file is write-only
        status.emplace_back(temp, State::WRITEONLY);
        file.close();
        continue;
      }
      QByteArray buffer = file.readAll();
      file.close();

      if (!file.open(QIODevice::WriteOnly |
                     QIODevice::Text)) {  // Check if the new file was created
                                          // and opened properly
        status.emplace_back(temp, State::READONLY);
        file.close();
        continue;
      }
      QTextStream out(&file);
      out << commentHeader(header.getContent(), l.second) << "\n\n" << buffer;
      status.emplace_back(temp, State::GOOD);
    } else {
      status.emplace_back(temp, State::FILEEXTENSION);
      continue;
    }
  }
  return true;
}
///
/// \brief Prepend the header and save the new files in a folder named
/// "AutoHeader". First the files are checked for compatibility. Then the
/// current content of the files to be processed is stored in a buffer. The
/// header is prepended to an new file and the old content will be appended to
/// the new file.
///
bool MainWindow::processFilesSafeMode() {
  QString temp;
  QString tempOut;
  QString dirName;
  std::pair<bool, Language::Language> l;
  for (int i = 0; i < fileNameList.length(); i++) {
    temp = currentDirectory.absolutePath() + "/" + fileNameList[i];
    QFileInfo fi(temp);
    l = readFileExtension(fi.completeSuffix().toUpper());
    if (l.first) {
      QFile file(temp);
      if (!file.open(QIODevice::ReadOnly |
                     QIODevice::Text)) {  // Check if file is write-only
        status.emplace_back(temp, State::WRITEONLY);
        file.close();
        continue;
      }
      QByteArray buffer = file.readAll();
      file.close();
      QDir newDir(currentDirectory);
      dirName = currentDirectory.absolutePath() + "/" + "AutoHeader";
      newDir.mkdir(dirName);
      tempOut = dirName + "/" + fileNameList[i];
      QFile outFile(tempOut);
      if (!outFile.open(QIODevice::WriteOnly |
                        QIODevice::Text)) {  // Check if the new file was
                                             // created and opened properly

        status.emplace_back(temp, State::READONLY);
        file.close();
        continue;
      }
      QTextStream out(&outFile);
      out << commentHeader(header.getContent(), l.second) << "\n\n" << buffer;
      status.emplace_back(tempOut, State::GOOD);
    } else {
      status.emplace_back(temp, State::FILEEXTENSION);
      continue;
    }
  }
  return true;
}

bool MainWindow::deleteHeader(int lineCount) {
  QString temp;
  std::pair<bool, Language::Language> l;
  int lc = 0;
  for (int i = 0; i < fileNameList.length(); i++) {
    temp = currentDirectory.absolutePath() + "/" + fileNameList[i];
    QFileInfo fi(temp);
    l = readFileExtension(fi.completeSuffix().toUpper());
    if (l.first) {
      QFile f(temp);
      if (f.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QString str;
        QTextStream t(&f);
        lc = 0;
        while (!t.atEnd()) {
          QString line = t.readLine();
          if (!line.startsWith(l.second.getSingleLine().at(0)) || lc >= lineCount) {
            str.append(line + "\n");
          }else{
              lc++;
            }
        }
        f.resize(0);
        t << str;
        f.close();
        status.emplace_back(temp, State::GOOD);
      } else {
        status.emplace_back(temp, State::UNKNOWN);
      }
    } else {
      status.emplace_back(temp, State::FILEEXTENSION);
      continue;
    }
  }
  return true;
}
///
/// \brief Get the corresponding language of a file-extension.
/// \param File-extension
/// \return The programming-langugage of a prefix and wether it is a valid
/// extension at all.
///
std::pair<bool, Language::Language> MainWindow::readFileExtension(
    const QString& suffix) {
  auto count = extensions.count(suffix);
  if (count > 0) {
    auto i = extensions.find(suffix)->second;
    return std::make_pair(true, languages.find(i)->second);
  }
  return std::make_pair(false, languages.find(0)->second);
}
///
/// \brief Prints a list with the files to be printed and their status to a
/// csv-file.
///
void MainWindow::printResultsToFile() {
  sort(status.begin(), status.end());
  status.erase(unique(status.begin(), status.end()), status.end());

  QString resultsPath = currentDirectory.absolutePath() + "/" + "results.csv";
  QFile file(resultsPath);
  if (!file.open(QIODevice::WriteOnly)) {
    return;
  }

  QTextStream out(&file);
  out << "File path"
      << ","
      << "Status"
      << "\n";
  for (auto& statu : status) {
    out << statu.first << "," << statu.second << "\n";
  }
  file.close();
}
void MainWindow::on_startButton_clicked() {
  disableUi();
  header.readUser();

  (safeMode) ? processFilesSafeMode() : processFiles();

  printResultsToFile();
  QMessageBox msgBox;
  msgBox.setText(
      "Process finished! Check \"results.csv\" for further information.");
  msgBox.exec();
  enableUi();
}

void MainWindow::enableUi() { ui->centralWidget->setEnabled(true); }
void MainWindow::disableUi() { ui->centralWidget->setEnabled(false); }

///
/// \brief Check MIME-type
/// \param Path to the file to check,
/// \return Wether the file is a tet file or should be skipped by the program.
///
bool MainWindow::checkMIME(const QString& path) {
  QMimeDatabase db;
  QMimeType type = db.mimeTypeForFile(path);
  return type.inherits("text/plain");
}

void MainWindow::warning() {
  QMessageBox msgBox;
  msgBox.setText(
      "AutoHeader is still in beta. Please create a backup of your files "
      "before your use this experimental version. By clicking \"safe-mode\" "
      "the program won't overwrite your files.");
  msgBox.exec();
}

void MainWindow::on_safeModeCheckBox_stateChanged(int arg1) {
  if (arg1 == 2) {
    safeMode = true;
  } else {
    safeMode = false;
  }
}

void MainWindow::on_forceSingleLine_stateChanged(int arg1) {
  if (arg1 == 2) {
    this->header.forceSingleLine = true;
  } else {
    this->header.forceSingleLine = false;
  }
}

void MainWindow::on_removeLinesButton_clicked() {
  disableUi();
  deleteHeader(5);
  enableUi();
}
