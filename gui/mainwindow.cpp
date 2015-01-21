#include "mainwindow.hpp"
#include "screen.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto* screen = new Screen;
    setCentralWidget(screen);
}
