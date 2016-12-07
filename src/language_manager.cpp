#include "language_manager.hpp"
#include "game_enums.hpp"
#include "xml_settings.hpp"

XmlSettings & languageSettings = XmlSettings::LoadSettings();

QString LanguageManager::MainMenu()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Main Menu";
      break;
  case RU:
      return "Главное меню";
      break;
  default:
      return "Main Menu";
      break;
  }
}
QString LanguageManager::StartGame()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Start new game";
      break;
  case RU:
      return "Начать новую игру";
      break;
  default:
      return "Start new game";
      break;
  }
}
QString LanguageManager::ExitGame()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Exit";
      break;
  case RU:
      return "Выход";
      break;
  default:
      return "Exit";
      break;
  }
}
QString LanguageManager::Settings()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Settings";
      break;
  case RU:
      return "Настройки";
      break;
  default:
      return "Settings";
      break;
  }
}
QString LanguageManager::Difficulty()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Difficulty";
      break;
  case RU:
      return "Сложность";
      break;
  default:
      return "Difficulty";
      break;
  }
}
QString LanguageManager::Easy()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Easy";
      break;
  case RU:
      return "Просто";
      break;
  default:
      return "Easy";
      break;
  }
}
QString LanguageManager::Medium()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Medium";
      break;
  case RU:
      return "Средне";
      break;
  default:
      return "Medium";
      break;
  }
}
QString LanguageManager::Hard()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Hard";
      break;
  case RU:
      return "Сложно";
      break;
  default:
      return "Hard";
      break;
  }
}
QString LanguageManager::Language()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Language";
      break;
  case RU:
      return "Язык";
      break;
  default:
      return "Language";
      break;
  }
}
QString LanguageManager::En()
{
  switch (languageSettings.m_language) {
  case EN:
      return "English";
      break;
  case RU:
      return "Английский";
      break;
  default:
      return "English";
      break;
  }
}
QString LanguageManager::Ru()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Russian";
      break;
  case RU:
      return "Русский";
      break;
  default:
      return "Russian";
      break;
  }
}
QString LanguageManager::BackToMainMenu()
{
  switch (languageSettings.m_language) {
  case EN:
      return "Back to main menu";
      break;
  case RU:
      return "Назад в главное меню";
      break;
  default:
      return "Back to main menu";
      break;
  }
}
