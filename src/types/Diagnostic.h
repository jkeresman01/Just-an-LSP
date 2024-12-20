#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../enums/DiagnosticSeverity.h"
#include "Range.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class Diagnostic
///
/// @brief Represents a diagnostic item in language server protocol
///
//////////////////////////////////////////////////////////////
class Diagnostic
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a Diagnostic item with specified range.
    ///
    /// @param range
    /// @param severity
    /// @param source
    /// @param message
    ///
    //////////////////////////////////////////////////////////////
    Diagnostic(const Range &range, const DiagnosticSeverity &severity, const std::string &source,
               const std::string &message);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes Diagnostics item to JSON format
    ///
    /// @return Diagnostics item in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range in the source code where the diagnostic applies.
    ///
    //////////////////////////////////////////////////////////////
    Range m_range;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The severity level of the diagnostic
    ///
    //////////////////////////////////////////////////////////////
    DiagnosticSeverity m_severity;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Specifies the source
    ///
    //////////////////////////////////////////////////////////////
    std::string m_source;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The diagnostic message
    ///
    //////////////////////////////////////////////////////////////
    std::string m_message;
};

} // namespace justanlsp
