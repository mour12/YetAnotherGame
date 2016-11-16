#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <iostream>

class SettingsWindow : public QMainWindow
{
  Q_OBJECT

public:
  SettingsWindow();

private slots:
  void OnDifficultyChanged(int index);
  void OnLanguageChanged(int index);
};
