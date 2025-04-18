#pragma once

#include <string>

#include "Range.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct Location
///
/// @Brief  Represents a location inside a resource,
///         such as a line inside a text file.
///
//////////////////////////////////////////////////////////////
struct Location
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Document URI
    ///
    //////////////////////////////////////////////////////////////
    std::string URI;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Range in the document
    ///
    //////////////////////////////////////////////////////////////
    Range range;
};
} // namespace justanlsp
