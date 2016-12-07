#include "game_constants.hpp"
#include "game_enums.hpp"
#include "xml_settings.hpp"

XmlSettings & difficultySettings = XmlSettings::LoadSettings();

float ConstantContainer::Speed()
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
int ConstantContainer::GunHp()
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
int ConstantContainer::BulletDamage()
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
int ConstantContainer::ObstacleQuantity()
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
int ConstantContainer::AlienQuantity()
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
float ConstantContainer::AlienSize()
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
float ConstantContainer::ObstacleSize()
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
