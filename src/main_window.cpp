#include "main_window.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  QGridLayout *layout = new QGridLayout(this);

  QPushButton *startGame = new QPushButton("Start new game");
  connect(startGame, SIGNAL(clicked()), SLOT(StartGame()));
  layout->addWidget(startGame, 0, 0);

  QPushButton *settings = new QPushButton("Settings");
  connect(settings, SIGNAL(clicked()), SLOT(OpenSettings()));
  layout->addWidget(settings, 1, 0);

  QPushButton *exitGame = new QPushButton("Exit");
  connect(exitGame, SIGNAL(clicked()), SLOT(close()));
  layout->addWidget(exitGame, 2, 0);

  QWidget *window = new QWidget();
  window->setLayout(layout);

  setCentralWidget(window);
}

void MainWindow::StartGame()
{
  //
}

void MainWindow::OpenSettings()
{
  SettingsWindow *settings = new SettingsWindow();
  settings->show();
  settings->showFullScreen();
}
