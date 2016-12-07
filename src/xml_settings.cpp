#include "xml_settings.hpp"
#include "3party/pugixml/src/pugixml.hpp"

XmlSettings::XmlSettings()
{
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file("settings.xml", pugi::parse_default | pugi::parse_declaration);
  if (result)
  {
    pugi::xml_node root = doc.document_element();

    pugi::xml_node difficulty = root.child("difficulty");
    if (!difficulty.empty())
      m_difficulty = static_cast<GameDifficulty>(difficulty.attribute("value").as_int());

    pugi::xml_node language = root.child("language");
    if (!language.empty())
      m_language = static_cast<Language>(language.attribute("value").as_int());
  }
}

void XmlSettings::SaveSettings()
{
  pugi::xml_document doc;
  auto declarationNode = doc.append_child(pugi::node_declaration);

  declarationNode.append_attribute("version") = "1.0";
  declarationNode.append_attribute("encoding") = "UTF-8";

  auto root = doc.append_child("settings");

  root.append_child("difficulty").append_attribute("value").set_value(m_difficulty);
  root.append_child("language").append_attribute("value").set_value(m_language);

  doc.save_file("settings.xml", PUGIXML_TEXT(" "));
}
