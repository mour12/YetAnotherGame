#include "main_window.hpp"
#include "gl_widget.hpp"
#include "xml_settings.hpp"
#include "language_manager.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QtWidgets/QComboBox>

typedef void (QWidget::*QWidgetVoidSlot)();

XmlSettings & settings = XmlSettings::LoadSettings();
LanguageManager & language = LanguageManager::GetLanguageManager();

MainWindow::MainWindow()
{
  m_widgets = new QStackedWidget(this);
  m_widgets->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  InitMainMenu();
  InitSettings();
  InitGame();

  setCentralWidget(m_widgets);
}

void MainWindow::StartGame()
{
  m_widgets->setCurrentIndex(2);
}

void MainWindow::OpenSettings()
{
  m_widgets->setCurrentIndex(1);
}

void MainWindow::OnDifficultyChanged(int index)
{
  settings.m_difficulty = static_cast<GameDifficulty>(index);
  settings.SaveSettings();
}

void MainWindow::OnLanguageChanged(int index)
{
    settings.m_language = static_cast<Language>(index);
    settings.SaveSettings();
}

void MainWindow::OnSettingsClosed()
{
  m_widgets->setCurrentIndex(0);
}

void MainWindow::InitMainMenu()
{
  auto mainWrapper = new QWidget(m_widgets);
  auto mainWrapperLayout = new QHBoxLayout(mainWrapper);

  QGroupBox * mainBox = new QGroupBox(language.MainMenu(), mainWrapper);
  mainWrapperLayout->addWidget(mainBox);

  mainBox->setFixedSize(300, 400);
  mainBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  mainBox->setAlignment(Qt::AlignCenter);
  m_widgets->insertWidget(0, mainWrapper);

  QGridLayout * mainBoxLayout = new QGridLayout(mainBox);

  QPushButton * startGame = new QPushButton(language.StartGame());
  connect(startGame, SIGNAL(clicked()), SLOT(StartGame()));
  mainBoxLayout->addWidget(startGame, 0, 0);

  QPushButton * settings = new QPushButton(language.Settings());
  connect(settings, SIGNAL(clicked()), SLOT(OpenSettings()));
  mainBoxLayout->addWidget(settings, 1, 0);

  QPushButton * exitGame = new QPushButton(language.ExitGame());
  connect(exitGame, SIGNAL(clicked()), SLOT(close()));
  mainBoxLayout->addWidget(exitGame, 2, 0);
}

void MainWindow::InitSettings()
{
  auto settingsWrapper = new QWidget(m_widgets);
  auto settingsWrapperLayout = new QHBoxLayout(settingsWrapper);

  QGroupBox * settingsBox = new QGroupBox("Settings", settingsWrapper);
  settingsWrapperLayout->addWidget(settingsBox);

  settingsBox->setFixedSize(300, 400);
  settingsBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  settingsBox->setAlignment(Qt::AlignCenter);
  m_widgets->insertWidget(1, settingsWrapper);

  QGridLayout * settingsBoxLayout = new QGridLayout(settingsBox);

  QHBoxLayout * hb1 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb1, 0, 0);
  hb1->addWidget(new QLabel(language.Difficulty()));

  QComboBox * difficultyCombobox = new QComboBox();
  difficultyCombobox->addItem(language.Easy());
  difficultyCombobox->addItem(language.Medium());
  difficultyCombobox->addItem(language.Hard());
  difficultyCombobox->setCurrentIndex(settings.m_difficulty);
  connect(difficultyCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnDifficultyChanged(int)));
  hb1->addWidget(difficultyCombobox);

  QHBoxLayout * hb2 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb2, 1, 0);
  hb2->addWidget(new QLabel(language.Language()));

  QComboBox * languageCombobox = new QComboBox();
  languageCombobox->addItem(language.En());
  languageCombobox->addItem(language.Ru());
  languageCombobox->setCurrentIndex(settings.m_language);
  connect(languageCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnLanguageChanged(int)));
  hb2->addWidget(languageCombobox);

  QHBoxLayout * hb3 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb3, 2, 0);

  QPushButton * exitSettings = new QPushButton(language.BackToMainMenu());
  connect(exitSettings, SIGNAL(clicked()), SLOT(OnSettingsClosed()));
  hb3->addWidget(exitSettings);
}

void MainWindow::InitGame()
{
  m_glWidget = new GLWidget(this, qRgb(0, 0, 0));
  m_glWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  m_widgets->insertWidget(2, m_glWidget);

  m_timer = new QTimer(this);
  m_timer->setInterval(10);

  connect(m_timer, &QTimer::timeout, m_glWidget, static_cast<QWidgetVoidSlot>(&QWidget::update));
  m_timer->start();
}
