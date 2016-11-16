#include <QApplication>
#include <QMainWindow>
#include <QSurfaceFormat>
#include "main_window.hpp"

int main(int argc, char ** argv)
{
  QApplication a(argc, argv);

  MainWindow mw;
  mw.show();
  mw.showFullScreen();
  return a.exec();
}
