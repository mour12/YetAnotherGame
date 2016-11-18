#include "main_window.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  auto centralWidget = new QWidget(this);
  QHBoxLayout * mainLayout = new QHBoxLayout(centralWidget);
  QGroupBox * box = new QGroupBox("Main menu", centralWidget);
  QGridLayout * boxLayout = new QGridLayout(box);
  mainLayout->addWidget(box);

  box->setFixedSize(300, 400);
  box->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  box->setAlignment(Qt::AlignCenter);

  QPushButton * startGame = new QPushButton("Start new game");
  connect(startGame, SIGNAL(clicked()), SLOT(StartGame()));
  boxLayout->addWidget(startGame, 0, 0);

  QPushButton * settings = new QPushButton("Settings");
  connect(settings, SIGNAL(clicked()), SLOT(OpenSettings()));
  boxLayout->addWidget(settings, 1, 0);

  QPushButton * exitGame = new QPushButton("Exit");
  connect(exitGame, SIGNAL(clicked()), SLOT(close()));
  boxLayout->addWidget(exitGame, 2, 0);

  setCentralWidget(centralWidget);
}

void MainWindow::StartGame()
{
  //
}

void MainWindow::OpenSettings()
{
  SettingsWindow * settings = new SettingsWindow();
  settings->show();
  settings->showFullScreen();
}
