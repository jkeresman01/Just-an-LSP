#pragma once

#include <optional>
#include <string>

#include "../enums/ComletionTriggerKind.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @struct Range
///
/// @brief Contains additional information about the context
///        in which a completion was triggered.
///
//////////////////////////////////////////////////////////////
struct CompletionContext
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range's start positon
    ///
    //////////////////////////////////////////////////////////////
    CompletionTriggerKind completionTriggerKind;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The trigger character (a single character)
    ///        that has trigger code complete.
    ///
    //////////////////////////////////////////////////////////////
    std::optional<std::string> triggerCharacter;
};
} // namespace justanlsp
