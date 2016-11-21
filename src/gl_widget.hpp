#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTime>
#include "textured_rect.hpp"

#include <array>

class MainWindow;

QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLShader)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT
public:
  GLWidget(QWidget * p, QColor const & background);
  ~GLWidget();

protected:
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void initializeGL() override;

  void Update();
  void Render();

private:
  int L2D(int px) const { return px * devicePixelRatio(); }

  QWidget * m_parent;

  unsigned int m_frames = 0;
  QTime m_time;
  QColor m_background;
  QSize m_screenSize;

  QOpenGLTexture * m_texture = nullptr;
  TexturedRect * m_texturedRect = nullptr;

  std::vector<QVector3D> m_stars = std::vector<QVector3D>(150);
};
