#include "SnippetRepository.h"

#include "../Utils/Logger.h"
#include "ISnippetProvider.h"

#include <fstream>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

namespace justanlsp
{

std::multimap<std::string, std::string> SnippetRepository::load()
{
    std::ifstream snippetsFile(PREDEFINED_SNIPPETS_PATH);

    if (!snippetsFile.is_open())
    {
        JLSP_ERROR(STR("Failed to open snippet file: %s", snippetsFile.c_str()));
        return m_snippets;
    }

    load(snippetsFile);

    snippetsFile.close();

    return m_snippets;
}

void SnippetRepository::load(std::ifstream &in)
{
    nlohmann::json::json snippetsJson;
    in >> snippetsJson;

    for (const auto &[keyword, values] : snippetsJson.items())
    {
        for (const auto &snippet : values)
        {
            m_snippets.emplace(keyword, snippet);
        }
    }
}

} // namespace justanlsp
