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
  QGroupBox *box = new QGroupBox("Settings", this);
  QGridLayout *layout = new QGridLayout(box);

  box->setFixedSize(300, 400);
  box->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  QHBoxLayout *hb1 = new QHBoxLayout();
  hb1->addWidget(new QLabel("Difficulty"));
  QComboBox *difficultyCombobox = new QComboBox();
  difficultyCombobox->addItem("Easy");
  difficultyCombobox->addItem("Medium");
  difficultyCombobox->addItem("Hard");
  connect(difficultyCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnDifficultyChanged(int)));
  hb1->addWidget(difficultyCombobox);
  layout->addLayout(hb1, 0, 0);

  QHBoxLayout *hb2 = new QHBoxLayout();
  hb2->addWidget(new QLabel("Language"));
  QComboBox *languageCombobox = new QComboBox();
  languageCombobox->addItem("RU");
  languageCombobox->addItem("EN");
  connect(languageCombobox, SIGNAL(currentIndexChanged(int)), SLOT(OnLanguageChanged(int)));
  hb2->addWidget(languageCombobox);
  layout->addLayout(hb2, 1, 0);

  QHBoxLayout *hb3 = new QHBoxLayout();
  QPushButton *exitGame = new QPushButton("Back to main menu");
  connect(exitGame, SIGNAL(clicked()), SLOT(close()));
  layout->addWidget(exitGame, 2, 0);
  hb3->addWidget(exitGame);
  layout->addLayout(hb3, 2, 0);
}

void SettingsWindow::OnDifficultyChanged(int index)
{
  std::cout << "Difficulty called " << index << '\n';
}
void SettingsWindow::OnLanguageChanged(int index)
{
  std::cout << "Language called " << index << '\n';
}
