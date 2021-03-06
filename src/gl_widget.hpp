#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTime>
#include "textured_rect.hpp"
#include "space.hpp"

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
  void ConfigureSpace();
  ~GLWidget();

signals:
  void StopGame();

protected:
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void initializeGL() override;

  void Update();
  void RenderStars();
  void RenderSpace();
  void RenderGameEntity(std::shared_ptr<GameEntity> gameEntity, QOpenGLTexture * texture);

  void keyPressEvent(QKeyEvent * e) override;
  void keyReleaseEvent(QKeyEvent * e) override;

private:
  int L2D(int px) const { return px * devicePixelRatio(); }

  QWidget * m_parent;

  unsigned int m_frames = 0;
  QTime m_time;
  QColor m_background;
  QSize m_screenSize;

  QOpenGLTexture * m_starTexture = nullptr;
  QOpenGLTexture * m_alienTexture = nullptr;
  QOpenGLTexture * m_bulletTexture = nullptr;
  QOpenGLTexture * m_gunTexture = nullptr;
  QOpenGLTexture * m_obstacleTexture = nullptr;
  TexturedRect * m_texturedRect = nullptr;

  std::vector<float[4]> m_stars = std::vector<float[4]>(150);
  std::shared_ptr<Space> m_spacePtr = nullptr;
};
