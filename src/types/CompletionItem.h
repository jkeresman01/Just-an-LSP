#pragma once

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
    CompletionItem(const std::string &label, const std::string &detail, const std::string &documentation,
                   const std::string &insertedText)
        : m_label(label), m_detail(detail), m_documentation(documentation) {};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Builder for construction textDocument/completion items
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
        public:
            Builder& withLabel(const std::string &label)
            {
                m_label = label;
                return *this;
            }

            Builder& withDetail(const std::string detail)
            {
                m_detail = detail;
                return *this;
            }

            Builder& withInsertedText(const std::string &insertedText)
            {
                m_insertedText = insertedText;
                return *this;
            }

            Builder& withDocumentation(const std::string &documentation)
            {
                m_documentation = documentation;
                return *this;
            }

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
    nlohmann::json toJson() const
    {
        return {{"label", m_label}, {"detail", m_detail}, {"documentation", m_documentation}};
    }

  private:
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
};

} // namespace justanlsp
