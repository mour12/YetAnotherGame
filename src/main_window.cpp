#include "main_window.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QtWidgets/QComboBox>

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  auto centralWidget = new QWidget(this);

  QHBoxLayout * layout = new QHBoxLayout(centralWidget);
  layout->setAlignment(Qt::AlignCenter);

  m_widgets = new QStackedWidget(centralWidget);
  m_widgets->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  layout->addWidget(m_widgets);

  QGroupBox * mainBox = new QGroupBox("Main menu", centralWidget);
  mainBox->setFixedSize(300, 400);
  mainBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  mainBox->setAlignment(Qt::AlignCenter);
  m_widgets->insertWidget(0, mainBox);

  QGridLayout * mainBoxLayout = new QGridLayout(mainBox);

  QPushButton * startGame = new QPushButton("Start new game");
  connect(startGame, SIGNAL(clicked()), SLOT(StartGame()));
  mainBoxLayout->addWidget(startGame, 0, 0);

  QPushButton * settings = new QPushButton("Settings");
  connect(settings, SIGNAL(clicked()), SLOT(OpenSettings()));
  mainBoxLayout->addWidget(settings, 1, 0);

  QPushButton * exitGame = new QPushButton("Exit");
  connect(exitGame, SIGNAL(clicked()), SLOT(close()));
  mainBoxLayout->addWidget(exitGame, 2, 0);

  QGroupBox * settingsBox = new QGroupBox("Settings", centralWidget);
  settingsBox->setFixedSize(300, 400);
  settingsBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  settingsBox->setAlignment(Qt::AlignCenter);
  m_widgets->insertWidget(1, settingsBox);

  QGridLayout * settingsBoxLayout = new QGridLayout(settingsBox);

  QHBoxLayout * hb1 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb1, 0, 0);

  hb1->addWidget(new QLabel("Difficulty"));

  QComboBox * difficultyCombobox = new QComboBox();
  difficultyCombobox->addItem("Easy");
  difficultyCombobox->addItem("Medium");
  difficultyCombobox->addItem("Hard");
  connect(difficultyCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnDifficultyChanged(int)));
  hb1->addWidget(difficultyCombobox);

  QHBoxLayout * hb2 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb2, 1, 0);

  hb2->addWidget(new QLabel("Language"));

  QComboBox * languageCombobox = new QComboBox();
  languageCombobox->addItem("RU");
  languageCombobox->addItem("EN");
  connect(languageCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnLanguageChanged(int)));
  hb2->addWidget(languageCombobox);

  QHBoxLayout * hb3 = new QHBoxLayout();
  settingsBoxLayout->addLayout(hb3, 2, 0);

  QPushButton * exitSettings = new QPushButton("Back to main menu");
  connect(exitSettings, SIGNAL(clicked()), SLOT(OnSettingsClosed()));
  hb3->addWidget(exitSettings);

  setCentralWidget(centralWidget);
}

void MainWindow::StartGame()
{
  //
}

void MainWindow::OpenSettings()
{
  m_widgets->setCurrentIndex(1);
}

void MainWindow::OnDifficultyChanged(int index)
{
  std::cout << "Difficulty called " << index << '\n';
}

void MainWindow::OnLanguageChanged(int index)
{
  std::cout << "Language called " << index << '\n';
}

void MainWindow::OnSettingsClosed()
{
  m_widgets->setCurrentIndex(0);
}
