#pragma once

#include "../Enums/CompletionItemKind.h"

#include <nlohmann/json.hpp>
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct CompletionItem
///
/// @brief Represents a completion item in the language server protocol,
///
//////////////////////////////////////////////////////////////
class CompletionItem
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs textDocument/completion item
    ///
    /// @param label
    /// @param detail
    /// @param documentation
    /// @param detail
    ///
    //////////////////////////////////////////////////////////////
    CompletionItem(const std::string &label, const CompletionItemKind completionItemKind,
                   const std::string &detail, const std::string &documentation,
                   const std::string &insertedText);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Builder for construction textDocument/completion items
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
      public:
        Builder &withLabel(const std::string &label);

        Builder &withDetail(const std::string detail);

        Builder &withInsertedText(const std::string &insertedText);

        Builder &withDocumentation(const std::string &documentation);

      private:
        std::string m_label;
        std::string m_detail;
        std::string m_documentation;
        std::string m_insertedText;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the completion item to JSON format.
    ///
    /// @return Returns a JSON object representing the completion item,
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The label of the completion item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_label;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Additional detail about the completion item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_detail;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Documentation or extended information about the item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_documentation;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Text to ne inserted by the editor
    ///
    //////////////////////////////////////////////////////////////
    std::string m_insertText;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Completion item kind (QUICK_FIX, SNIPPET...)
    ///
    //////////////////////////////////////////////////////////////
    CompletionItemKind m_completionItemKind;
};

} // namespace justanlsp
