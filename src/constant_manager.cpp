#include "constant_manager.hpp"
#include "game_enums.hpp"
#include "xml_settings.hpp"

XmlSettings & difficultySettings = XmlSettings::LoadSettings();

float ConstantManager::Speed()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10.0f;
      break;
  case Medium:
      return 20.0f;
      break;
  case Hard:
      return 30.0f;
      break;
  default:
      return 10.0f;
      break;
  }
}
int ConstantManager::GunHp()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10;
      break;
  case Medium:
      return 5;
      break;
  case Hard:
      return 1;
      break;
  default:
      return 10;
      break;
  }
}
int ConstantManager::BulletDamage()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10;
      break;
  case Medium:
      return 5;
      break;
  case Hard:
      return 1;
      break;
  default:
      return 10;
      break;
  }
}
int ConstantManager::ObstacleQuantity()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10;
      break;
  case Medium:
      return 5;
      break;
  case Hard:
      return 1;
      break;
  default:
      return 10;
      break;
  }
}
int ConstantManager::AlienQuantity()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10;
      break;
  case Medium:
      return 20;
      break;
  case Hard:
      return 30;
      break;
  default:
      return 10;
      break;
  }
}
float ConstantManager::AlienSize()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10.0f;
      break;
  case Medium:
      return 20.0f;
      break;
  case Hard:
      return 30.0f;
      break;
  default:
      return 10.0f;
      break;
  }
}
float ConstantManager::ObstacleSize()
{
  switch (difficultySettings.m_difficulty) {
  case Easy:
      return 10.0f;
      break;
  case Medium:
      return 20.0f;
      break;
  case Hard:
      return 30.0f;
      break;
  default:
      return 10.0f;
      break;
  }
}
