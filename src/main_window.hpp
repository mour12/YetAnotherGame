#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <iostream>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QOpenGLWidget>
#include <QTimer>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private:
  QTimer * m_timer = nullptr;
  QOpenGLWidget * m_glWidget = nullptr;
  QStackedWidget * m_widgets = nullptr;

  void InitMainMenu();
  void InitSettings();
  void InitGame();
  void InitSettingsXml();

private slots:
  void StartGame();
  void OpenSettings();
  void OnDifficultyChanged(int index);
  void OnLanguageChanged(int index);
  void OnSettingsClosed();
};
