#pragma once

#include <unistd.h>
#include <string>

class XmlSettings
{
public:

  static XmlSettings & LoadSettings()
  {
    static XmlSettings instance;
    return instance;
  }

  void SaveSettings();

  int m_difficulty = 0;
  int m_language = 0;

private:
  XmlSettings();
  ~XmlSettings() {}
  XmlSettings(XmlSettings const &) = delete;
  XmlSettings & operator=(XmlSettings const &) = delete;
  XmlSettings(XmlSettings const &&) = delete;
  XmlSettings & operator=(XmlSettings const &&) = delete;
};
