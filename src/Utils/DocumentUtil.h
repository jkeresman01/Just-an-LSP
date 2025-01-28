#pragma once

#include <string>

#include "../Types/Position.h"
#include "../Utils/Logger.h"

namespace justanlsp
{

/////////////////////////////////////////////////////////////////////
///
/// @class TimeUtil
///
/// @brief Utility class for time related stuff
///
/////////////////////////////////////////////////////////////////////
class DocumentUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    DocumentUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Extract prefix from current positon in editor
    ///
    /// @param document
    /// @param position
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string extractPrefix(const std::string &document, const Position &position);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline std::string DocumentUtil::extractPrefix(const std::string &document, const Position &position)
{
    std::stringstream ss(document);

    std::string prefix;

    for (size_t i = 0; i < position.line; ++i)
    {
        getline(ss, prefix);
    }
    JLSP_DEBUG(STR("Extracted prefix %s from document: %s", prefix.c_str(), document.c_str()));

    return prefix;
}

} // namespace justanlsp
