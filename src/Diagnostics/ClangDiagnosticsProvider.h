#pragma once

#include <string>

#include "IDiagnosticsProvider.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ClangDiagnosticsProvider
///
/// @brief Implementation of the IDiagnosticsProvider interface
///        that provides diagnostics using Clang.
///
//////////////////////////////////////////////////////////////
class ClangDiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves diagnostics for a given document at a
    ///        specified position.
    ///
    /// @param document
    /// @param position
    ///
    /// @return A vector of Diagnostic objects representing the
    ///         issues found in the specified document.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<Diagnostic> getDiagnostics(const std::string &document, const Position &position) override;
};

} // namespace justanlsp
