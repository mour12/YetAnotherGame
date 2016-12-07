#pragma once

#include <unistd.h>
#include <string>
#include "game_enums.hpp"

class XmlSettings
{
public:

  static XmlSettings & LoadSettings()
  {
    static XmlSettings instance;
    return instance;
  }

  void SaveSettings();

  GameDifficulty m_difficulty = Easy;
  Language m_language = EN;

private:
  XmlSettings();
  ~XmlSettings() {}
  XmlSettings(XmlSettings const &) = delete;
  XmlSettings & operator=(XmlSettings const &) = delete;
  XmlSettings(XmlSettings const &&) = delete;
  XmlSettings & operator=(XmlSettings const &&) = delete;
};
