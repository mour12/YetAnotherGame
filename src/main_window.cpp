#include "main_window.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  QGroupBox * box = new QGroupBox("Settings", this);
  box->setFixedSize(600, 800);

  QGridLayout * layout = new QGridLayout(box);

  box -> setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  QHBoxLayout * hb1 = new QHBoxLayout();
  hb1->addWidget(new QLabel("Difficulty"));
  QComboBox * combobox = new QComboBox();
  combobox->addItem("Easy");
  combobox->addItem("Medium");
  combobox->addItem("Hard");
  hb1->addWidget(combobox);
  connect(hb1, SIGNAL(currentIndexChanged(int)), SLOT(OnDifficultyChanged(int)));
  layout->addLayout(hb1, 0, 0);

  QHBoxLayout * hb2 = new QHBoxLayout();
  hb2->addWidget(new QLabel("Max alien quantity"));
  QSpinBox * spinbox = new QSpinBox();
  spinbox->setRange(10, 1000);
  spinbox->setValue(100);
  hb2->addWidget(spinbox);
  layout->addLayout(hb2, 1, 0);

  QHBoxLayout * hb3 = new QHBoxLayout();
  hb3->addWidget(new QLabel("Alien speed"));
  QSpinBox * spinbox2 = new QSpinBox();
  spinbox2->setRange(1, 10);
  spinbox2->setValue(5);
  hb3->addWidget(spinbox2);
  layout->addLayout(hb3, 2, 0);
}

void MainWindow::OnDifficultyChanged(int index)
{
  std::cout << "I'm called" << index;
}
