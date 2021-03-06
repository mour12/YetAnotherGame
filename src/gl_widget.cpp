#include "gl_widget.hpp"
#include "language_manager.hpp"
#include "constant_manager.hpp"
#include "alien.hpp"
#include "obstacle.hpp"

#include <QPainter>
#include <QPaintEngine>
#include <QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QGuiApplication>
#include <cmath>
#include <QtGui/QtGui>
#include <QtWidgets/QMessageBox>
#include <iostream>

LanguageManager & languageManager = LanguageManager::GetLanguageManager();
ConstantManager & constantManager = ConstantManager::GetConstantManager();

GLWidget::GLWidget(QWidget * p, QColor const & background)
  : m_parent(p)
  , m_background(background)
{}

GLWidget::~GLWidget()
{
  makeCurrent();
  delete m_starTexture;
  delete m_alienTexture;
  delete m_texturedRect;
  doneCurrent();
}

void GLWidget::initializeGL()
{
  initializeOpenGLFunctions();

  m_texturedRect = new TexturedRect();
  m_texturedRect->Initialize(this);

  m_starTexture = new QOpenGLTexture(QImage("data/star.png"));
  m_alienTexture = new QOpenGLTexture(QImage("data/alien.png"));
  m_gunTexture = new QOpenGLTexture(QImage("data/gun.png"));
  m_bulletTexture = new QOpenGLTexture(QImage("data/bullet.png"));
  m_obstacleTexture = new QOpenGLTexture(QImage("data/box.jpg"));

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

  RenderStars();
  RenderSpace();

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
      star[0] = (float) (qrand() % 1000000) / 1000000;
      star[1] = (float) (qrand() % 1000000) / 1000000;
      star[2] = 0.0f;
      star[3] = 0.5f + (float) (qrand() % 1000000) / 1000000;
    }
  }
  m_spacePtr->Update();
}

void GLWidget::ConfigureSpace()
{
  m_spacePtr = std::make_shared<Space>(1.0f, 1.0f);
  auto alienSize = constantManager.AlienSize();
  float gap = (1 - 0.01f) / (constantManager.AlienQuantity() + 1);
  for (int i = 0; i < constantManager.AlienQuantity(); ++i)
  {
    auto leftBottomCorner = Point2D(0.005f + (i + 1) * gap - alienSize / 2, 1 - 0.005f);
    auto rightTopCorner = Point2D(0.005f + (i + 1) * gap + alienSize / 2, 1 - 0.005f - alienSize);
    auto alienBox = Box2D(leftBottomCorner, rightTopCorner);
    std::shared_ptr<Alien> alien = std::make_shared<Alien>(alienBox, Direction2D(-1.0f, 0.0f), constantManager.AlienSpeed(), constantManager.AlienHp(), Ray2D(alienBox.Center(), Direction2D(0.0f, -1.0f)), m_spacePtr);
    m_spacePtr->AddGameEntity(alien);
  }

  auto obstacleSize = constantManager.ObstacleSize();
  gap = (1 - 0.01f) / (constantManager.ObstacleQuantity() + 1);
  for (int i = 0; i < constantManager.ObstacleQuantity(); ++i)
  {
    auto leftBottomCorner = Point2D(0.005f + (i + 1) * gap - obstacleSize / 2, 0.3f);
    auto rightTopCorner = Point2D(0.005f + (i + 1) * gap + obstacleSize / 2, 0.3f + obstacleSize);
    auto obstacleBox = Box2D(leftBottomCorner, rightTopCorner);
    std::shared_ptr<Obstacle> obstacle = std::make_shared<Obstacle>(obstacleBox, constantManager.ObstacleHp(), m_spacePtr);
    m_spacePtr->AddGameEntity(obstacle);
  }

  auto gunSize = constantManager.GunSize();
  auto leftBottomCorner = Point2D(0.5f - gunSize / 2, 0.1f);
  auto rightTopCorner = Point2D(0.5f + gunSize / 2, 0.1f + gunSize);
  auto gunBox = Box2D(leftBottomCorner, rightTopCorner);
  std::shared_ptr<Gun> gun = std::make_shared<Gun>(gunBox, Direction2D(), 0.0f, constantManager.GunHp(), m_spacePtr);
  m_spacePtr->AddGameEntity(gun);
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

  if (e->key() == Qt::Key_Left)
  {
    for (auto & gameEntity : m_spacePtr->gameEntities())
    {
      if (gameEntity->GetType() == FactoryType::GunType)
      {
        gameEntity->direction() = Direction2D(-1.0f, 0.0f);
        gameEntity->velocity() = constantManager.GunSpeed();
        return;
      }
    }
  }

  if (e->key() == Qt::Key_Right)
  {
    for (auto & gameEntity : m_spacePtr->gameEntities())
    {
      if (gameEntity->GetType() == FactoryType::GunType)
      {
        gameEntity->direction() = Direction2D(1.0f, 0.0f);
        gameEntity->velocity() = constantManager.GunSpeed();
        return;
      }
    }
  }

  if (e->key() == Qt::Key_Space)
  {
    for (auto & gameEntity : m_spacePtr->gameEntities())
    {
      if (gameEntity->GetType() == FactoryType::GunType)
      {
        std::static_pointer_cast<Gun>(gameEntity)->Shoot();
        return;
      }
    }
  }
}

void GLWidget::keyReleaseEvent(QKeyEvent * e)
{
  if (e->key() == Qt::Key_Left || e->key() == Qt::Key_Right)
  {
    for (auto & gameEntity : m_spacePtr->gameEntities())
    {
      if (gameEntity->GetType() == FactoryType::GunType)
      {
        gameEntity->velocity() = 0.0f;
        return;
      }
    }
  }
}

void GLWidget::RenderStars()
{
  int constexpr kRectSize = 32;
  for (auto &star : m_stars)
  {
    int rectSize = kRectSize * star[3];
    m_texturedRect->Render(m_starTexture, sin(star[2] * M_PI), QVector2D(rectSize / 2 + star[0] * (m_screenSize.width() - rectSize), rectSize / 2 + star[1] * (m_screenSize.height() - rectSize)), QSize(rectSize, rectSize), m_screenSize);
  }
}

void GLWidget::RenderSpace()
{
  for (auto &gameEntity : m_spacePtr->gameEntities())
  {
    switch (gameEntity->GetType())
    {
      case FactoryType::AlienType:
        RenderGameEntity(gameEntity, m_alienTexture);
        break;
      case FactoryType::BulletType:
        RenderGameEntity(gameEntity, m_bulletTexture);
        break;
      case FactoryType::GunType:
        RenderGameEntity(gameEntity, m_gunTexture);
        break;
      case FactoryType::ObstacleType:
        RenderGameEntity(gameEntity, m_obstacleTexture);
        break;
    }
  }
}

void GLWidget::RenderGameEntity(std::shared_ptr<GameEntity> gameEntity, QOpenGLTexture * texture)
{
  m_texturedRect->Render(texture, 1.0f, QVector2D(gameEntity->box().Center().x() * m_screenSize.width(), gameEntity->box().Center().y() * m_screenSize.height()), QSize(gameEntity->box().Width() * m_screenSize.width(), gameEntity->box().Height() * m_screenSize.height()), m_screenSize);
}
