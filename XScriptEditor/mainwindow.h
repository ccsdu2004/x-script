#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "xscriptledit.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
  private:
    XScriptEdit* edit = nullptr;
};
#endif // MAINWINDOW_H
