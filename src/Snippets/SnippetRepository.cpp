#include "SnippetRepository.h"

#include <nlohmann/json.hpp>

#include "../Utils/Logger.h"

namespace justanlsp
{
SnippetsT SnippetRepository ::load()
{
    std::ifstream snippetsFile(PREDEFINED_SNIPPETS_PATH);

    if (!snippetsFile.is_open())
    {
        JLSP_ERROR(STR("No can do for %s", PREDEFINED_SNIPPETS_PATH));
        return {};
    }

    load(snippetsFile);
    snippetsFile.close();

    return m_snippets;
}

void SnippetRepository::load(std::ifstream &snippetsFile)
{
    nlohmann::json snippetsJson;
    snippetsFile >> snippetsJson;

    for (auto &[key, snippets] : snippetsJson.items())
    {
        for (const auto &snippet : snippets)
        {
            m_snippets.insert({key, snippet});
        }
    }
}
} // namespace justanlsp
