#include "gl_widget.hpp"

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QGuiApplication>

GLWidget::GLWidget(QWidget * p, QColor const & background)
  : m_parent(p)
  , m_background(background)
{}

GLWidget::~GLWidget()
{
  makeCurrent();
  delete m_texture;
  delete m_texturedRect;
  doneCurrent();
}

void GLWidget::initializeGL()
{
  initializeOpenGLFunctions();

  m_texturedRect = new TexturedRect();
  m_texturedRect->Initialize(this);

  m_texture = new QOpenGLTexture(QImage("data/star.png"));

  for (auto &star : m_stars) {
    star.setX((float)(qrand() % 100000) / 100000);
    star.setY((float)(qrand() % 100000) / 100000);
    star.setZ((float)(qrand() % 100000) / 100000);
  }

  m_time.start();
}

void GLWidget::paintGL()
{
  int const elapsed = m_time.elapsed();
  Update(elapsed / 1000.0f);

  QPainter painter;
  painter.begin(this);
  painter.beginNativePainting();

  glClearColor(m_background.redF(), m_background.greenF(), m_background.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glFrontFace(GL_CW);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Render();

  glDisable(GL_CULL_FACE);
  glDisable(GL_BLEND);

  painter.endNativePainting();

  if (elapsed != 0)
  {
    QString framesPerSecond;
    framesPerSecond.setNum(m_frames / (elapsed / 1000.0), 'f', 2);
    painter.setPen(Qt::white);
    painter.drawText(20, 40, framesPerSecond + " fps");
  }
  painter.end();

  if (!(m_frames % 100))
  {
    m_time.start();
    m_frames = 0;
  }
  ++m_frames;
  update();
}

void GLWidget::resizeGL(int w, int h)
{
  m_screenSize.setWidth(w);
  m_screenSize.setHeight(h);
}

void GLWidget::Update(float elapsedSeconds)
{
//
}

void GLWidget::Render()
{
  for (auto &star : m_stars)
  {
    m_texturedRect->Render(m_texture, QVector2D(16 + star.x() * (m_screenSize.width() - 32), 16 + star.y() * (m_screenSize.height() - 32)), QSize(32, 32), m_screenSize);
  }
}
