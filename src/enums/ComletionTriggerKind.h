#pragma once

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @enum CompletionTriggerKind
///
/// @brief How a completion was triggered
///
//////////////////////////////////////////////////////////////
enum class CompletionTriggerKind
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Completion was triggered by typing an identifier
    ///        (24x7 code complete), manual invocation
    ///        (e.g Ctrl+Space) or via API.
    ///
    //////////////////////////////////////////////////////////////
    INVOKED = 1,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Completion was triggered by a trigger character
    ///        specified by the `triggerCharacters` properties of
    ///        the CompletionRegistrationOptions`
    ///
    //////////////////////////////////////////////////////////////
    TRIGGER_CHARACTER = 2,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Completion was re-triggered as the current
    ///        completion list is incomplete.
    ///
    //////////////////////////////////////////////////////////////
    TRIGGER_FOR_INCOMPLETE_COMPLETIONS = 3,
};
} // namespace justanlsp