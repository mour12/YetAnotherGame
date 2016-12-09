#include "constant_manager.hpp"
#include "game_enums.hpp"
#include "xml_settings.hpp"

XmlSettings & difficultySettings = XmlSettings::LoadSettings();

float ConstantManager::AlienSpeed()
{
  switch (difficultySettings.m_difficulty)
  {
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
  switch (difficultySettings.m_difficulty)
  {
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

int ConstantManager::AlienHp()
{
  switch (difficultySettings.m_difficulty)
  {
    case Easy:
      return 1;
      break;
    case Medium:
      return 3;
      break;
    case Hard:
      return 5;
      break;
    default:
      return 1;
      break;
  }
}

int ConstantManager::ObstacleHp()
{
  switch (difficultySettings.m_difficulty)
  {
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
  switch (difficultySettings.m_difficulty)
  {
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
  switch (difficultySettings.m_difficulty)
  {
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
  switch (difficultySettings.m_difficulty)
  {
    case Easy:
      return 0.10f;
      break;
    case Medium:
      return 0.05f;
      break;
    case Hard:
      return 0.02f;
      break;
    default:
      return 0.10f;
      break;
  }
}

float ConstantManager::ObstacleSize()
{
  switch (difficultySettings.m_difficulty)
  {
    case Easy:
      return 0.08f;
      break;
    case Medium:
      return 0.04f;
      break;
    case Hard:
      return 0.02f;
      break;
    default:
      return 0.08f;
      break;
  }
}
