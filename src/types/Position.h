#pragma once

#include <cstdint>
#include <sstream>
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct ServerInfo
///
/// @brief Position in a text document expressed as zero-based 
///        line and zero-based character offset
///
//////////////////////////////////////////////////////////////
struct Position
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Line position in a document (zero-based).
    ///
    //////////////////////////////////////////////////////////////
    uint64_t line;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Character offset on a line in a document (zero-based).
    ///
    //////////////////////////////////////////////////////////////
    uint64_t character;
};
}
