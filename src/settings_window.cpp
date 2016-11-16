#include "settings_window.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>

typedef void (QWidget::*QWidgetVoidSlot)();

SettingsWindow::SettingsWindow()
{
  auto centralWidget = new QWidget(this);
  QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
  QGroupBox *box = new QGroupBox("Settings", centralWidget);
  QGridLayout *boxLayout = new QGridLayout(box);
  mainLayout->addWidget(box);

  box->setFixedSize(300, 400);
  box->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  box->setAlignment(Qt::AlignCenter);

  QHBoxLayout *hb1 = new QHBoxLayout();
  hb1->addWidget(new QLabel("Difficulty"));
  QComboBox *difficultyCombobox = new QComboBox();
  difficultyCombobox->addItem("Easy");
  difficultyCombobox->addItem("Medium");
  difficultyCombobox->addItem("Hard");
  connect(difficultyCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnDifficultyChanged(int)));
  hb1->addWidget(difficultyCombobox);
  boxLayout->addLayout(hb1, 0, 0);

  QHBoxLayout *hb2 = new QHBoxLayout();
  hb2->addWidget(new QLabel("Language"));
  QComboBox *languageCombobox = new QComboBox();
  languageCombobox->addItem("RU");
  languageCombobox->addItem("EN");
  connect(languageCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnLanguageChanged(int)));
  hb2->addWidget(languageCombobox);
  boxLayout->addLayout(hb2, 1, 0);

  QHBoxLayout *hb3 = new QHBoxLayout();
  QPushButton *exitSettings = new QPushButton("Back to main menu");
  connect(exitSettings, SIGNAL(clicked()), SLOT(close()));
  hb3->addWidget(exitSettings);
  boxLayout->addLayout(hb3, 2, 0);

  setCentralWidget(centralWidget);
}

void SettingsWindow::OnDifficultyChanged(int index)
{
  std::cout << "Difficulty called " << index << '\n';
}
void SettingsWindow::OnLanguageChanged(int index)
{
  std::cout << "Language called " << index << '\n';
}
