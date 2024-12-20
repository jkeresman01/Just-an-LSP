#pragma once

#include <nlohmann/json.hpp>

#include "Position.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct Range
///
/// @brief A range in a text document expressed as (zero-based)
///        start and end positions. A range is comparable to a
///        selection in an editor. Therefore, the end position
///        is exclusive
///
//////////////////////////////////////////////////////////////
struct Range
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range's start positon
    ///
    //////////////////////////////////////////////////////////////
    Position start;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range's end positon
    ///
    //////////////////////////////////////////////////////////////
    Position end;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the Range to JSON format
    ///
    /// @return Range in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const
    {
        return {
            {"start", start.toJson()},
            {"end", end.toJson()},
        };
    }
};
} // namespace justanlsp
