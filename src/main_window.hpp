#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <iostream>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QOpenGLWidget>
#include <QTimer>
#include "gl_widget.hpp"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private:
  QTimer * m_timer = nullptr;
  GLWidget * m_glWidget = nullptr;
  QStackedWidget * m_widgets = nullptr;

  void InitMainMenu();
  void InitSettings();
  void InitGame();

private slots:
  void StartGame();
  void StopGame();
  void OpenSettings();
  void OnDifficultyChanged(int index);
  void OnLanguageChanged(int index);
  void OnSettingsClosed();
};
