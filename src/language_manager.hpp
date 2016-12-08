#pragma once

#include <QString>

class LanguageManager
{
public:

  static LanguageManager & GetLanguageManager()
  {
    static LanguageManager instance;
    return instance;
  }

  QString MainMenu();
  QString StartGame();
  QString ExitGame();
  QString Settings();
  QString Difficulty();
  QString Easy();
  QString Medium();
  QString Hard();
  QString Language();
  QString En();
  QString Ru();
  QString BackToMainMenu();
  QString RestartGameMessageBox();

private:
  LanguageManager() {}
  ~LanguageManager() {}
  LanguageManager(LanguageManager const &) = delete;
  LanguageManager & operator=(LanguageManager const &) = delete;
  LanguageManager(LanguageManager const &&) = delete;
  LanguageManager & operator=(LanguageManager const &&) = delete;
};
