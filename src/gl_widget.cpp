#include "gl_widget.hpp"
#include "language_manager.hpp"

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QGuiApplication>
#include <cmath>
#include <QtGui/QtGui>
#include <QtWidgets/QMessageBox>

LanguageManager & languageManager = LanguageManager::GetLanguageManager();

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
    star[0] = (float)(qrand() % 1000000) / 1000000;
    star[1] = (float)(qrand() % 1000000) / 1000000;
    star[2] = (float)(qrand() % 1000000) / 1000000;
    star[3] = 0.5f + (float)(qrand() % 1000000) / 1000000;
  }

  m_time.start();
}

void GLWidget::paintGL()
{
  int const elapsed = m_time.elapsed();
  Update();

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

void GLWidget::Update()
{
  for (auto &star : m_stars)
  {
    star[2] += 0.001f;
    if (star[2] >= 1.0f)
    {
      star[0] = (float)(qrand() % 1000000) / 1000000;
      star[1] = (float)(qrand() % 1000000) / 1000000;
      star[2] = 0.0f;
      star[3] = 0.5f + (float)(qrand() % 1000000) / 1000000;
    }
  }
}

void GLWidget::keyPressEvent(QKeyEvent * e)
{
  if (e->key() == Qt::Key_Escape)
  {
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setText(languageManager.PauseGame());
    int ret = msgBox.exec();
    switch (ret)
    {
      case QMessageBox::Yes:
        return;
      case QMessageBox::No:
        emit StopGame();
      default:
        return;
    }
  }
}

void GLWidget::Render()
{
  int constexpr kRectSize = 32;
  for (auto &star : m_stars)
  {
    int rectSize = kRectSize * star[3];
    m_texturedRect->Render(m_texture, sin(star[2] * M_PI), QVector2D(rectSize / 2 + star[0] * (m_screenSize.width() - rectSize), rectSize / 2 + star[1] * (m_screenSize.height() - rectSize)), QSize(rectSize, rectSize), m_screenSize);
  }
}
