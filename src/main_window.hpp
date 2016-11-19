#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <iostream>
#include <QtWidgets/QStackedWidget>
#include "settings_window.hpp"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private:
  QStackedWidget * m_widgets;

private slots:
  void StartGame();
  void OpenSettings();
  void OnDifficultyChanged(int index);
  void OnLanguageChanged(int index);
  void OnSettingsClosed();
};
