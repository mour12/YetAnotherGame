#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QGridLayout>
#include <QOpenGLWidget>
#include <iostream>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private slots:
  void OnDifficultyChanged(int index);
};
