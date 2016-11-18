#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <iostream>
#include "settings_window.hpp"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private slots:
  void StartGame();
  void OpenSettings();
};
