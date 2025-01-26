#include "ConfigurationManager.h"

#include "../Utils/Logger.h"

#include <fstream>
#include <mutex>
#include <string>

namespace justanlsp
{

ConfigurationManager *ConfigurationManager::s_instance = nullptr;
std::mutex ConfigurationManager::s_mutex;

void ConfigurationManager::load()
{
    m_properties.clear();

    std::ifstream in(XML_CONFIGURATION_PATH);

    if (!in)
    {
        JLSP_ERROR(STR("No can do for config file: %s", XML_CONFIGURATION_PATH));
        return;
    }

    load(in);

    in.close();
}

std::string ConfigurationManager::getProperty(const std::string_view &propertyName)
{
    auto it = m_properties.find(propertyName);

    if (it == m_properties.end())
    {
        JLSP_ERROR(STR("No can do for property: %s", propertyName));
        return std::string();
    }

    return it->second;
}

void ConfigurationManager::load(std::ifstream &in)
{
    std::string line;

    while (getline(in, line))
    {
        std::pair<std::string, std::string> property = XMLUtil::parseFromFileLine(line);

        if (property.first != "" and property.second != "")
        {
            m_properties.insert(property);
        }
        else
        {
            JLSP_ERROR(STR("Found empty propery: [\"%s\"] : [\"%s\"]", property.first.c_str(),
                           property.second.c_str()));
        }
    }
}

ConfigurationManager::~ConfigurationManager()
{
    if (s_instance)
    {
        delete s_instance;
    }
}

ConfigurationManager *ConfigurationManager::getInstance()
{
    std::lock_guard<std::mutex> lock(s_mutex);

    if (!s_instance)
    {
        s_instance = new ConfigurationManager();
    }

    return s_instance;
}
} // namespace justanlsp
