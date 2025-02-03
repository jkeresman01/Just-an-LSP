#pragma once

#include <string>

#include "IDiagnosticsProvider.h"

#include <clang/AST/AST.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Frontend/ASTConsumers.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/ParseableAST.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Parse/Parser.h>
#include <clang/Tooling/Tooling.h>

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
    ClangDiagnosticsProvider();

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

  private:
    clang::CompilerInstance m_compilerInstance;
    clang::DiagnosticOptions m_diagnosticsTag;
    clang::DiagnosticsEngine m_diagnosticsEngine;
    clang::FileManager m_fileManager;
    clang::SourceManager m_sourceManager;
    clang::FileID m_fileID;

    llvm::MemoryBuffer *m_memmoryBuffer;

    std::unique_ptr<clang::TextDiagnosticPrinter> m_diagnosticsPrinter;
    std::unique_ptr<clang::ASTConsumer> m_astConsumer;
};

} // namespace justanlsp
