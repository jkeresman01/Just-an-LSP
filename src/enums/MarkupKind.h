#pragma once

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @enum MarkupKind
///
/// @brief Describes the content type that a client supports in
///        various result literals like `Hover`,
///        `ParameterInfo` or `CompletionItem`.
///
///
//////////////////////////////////////////////////////////////
enum class MarkupKind
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Plain text is supported as a content format
    ///
    //////////////////////////////////////////////////////////////
    PLAIN_TEXT,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Markdown is supported as a content format
    ///
    //////////////////////////////////////////////////////////////
    MARKDOWN,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Used for getting max number of possible markup kind
    ///        values
    ///
    //////////////////////////////////////////////////////////////
    MAX_NUMBER_OF_OPTIONS,
};

} // namespace justanlsp