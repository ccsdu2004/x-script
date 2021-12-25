#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    edit = new XScriptEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow() {
}

