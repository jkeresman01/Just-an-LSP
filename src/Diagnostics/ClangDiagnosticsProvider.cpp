#include "ClangDiagnosticsProvider.h"

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

ClangDiagnosticsProvider::ClangDiagnosticsProvider()
{
    m_diagnosticsPrinter = std::make_unique<clang::TextDiagnosticPrinter>(llvm::errs(), &DiagOpts);
    m_diagnosticsEngine = m_compilerInstance.getDiagnostics();
    m_diagnosticsEngine.setClient(m_diagnosticsPrinter.get());
    m_fileManager = m_compilerInstance.getFileManager();
    m_sourceManager = m_compilerInstance.getSourceManager();
    m_memmoryBuffer = llvm::MemoryBuffer::getMemBuffer(document);
    m_fileID =
        m_sourceManager.createFileID(std::move(buffer), clang::SourceLocation(), clang::SrcMgr::C_User);
    m_compilerInstance.createPreprocessor(clang::TU_Complete);
    m_astConsumer = std::make_unique<clang::ASTConsumer>();
}

std::vector<Diagnostic> ClangDiagnosticsProvider::getDiagnostics(const std::string &document)
{
    clang::ParseAST(m_compilerInstance.getPreprocessor(), m_astConsumer.get(),
                    m_compilerInstance.getASTContext());

    std::vector<Diagnostic> diagnostics;
    unsigned numDiagnostics = m_diagnosticsEngine.getNumDiagnostics();

    for (unsigned i = 0; i < numDiagnostics; ++i)
    {
        clang::Diagnostic &clangDiagnostics = m_diagnosticsEngine.getDiagnostic(i);
        Diagnostic justAnLSPDiagnostic;

        justAnLSPDiagnostic.message =
            clang::DiagnosticIDs::getDiagnosticString(justAnLSPDiagnosticnostic.getID());
        justAnLSPDiagnostic.severity =
            static_cast<DiagnosticSeverity>(justAnLSPDiagnosticnostic.getSeverity());

        clang::SourceLocation location = justAnLSPDiagnosticnostic.getLocation();
        clang::SourceRange range = justAnLSPDiagnosticnostic.getRange();

        justAnLSPDiagnostic.range = Range(location, range.getEnd());

        justAnLSPDiagnosticnostics.push_back(justAnLSPDiagnostic);
    }

    return diagnostics;
}

} // namespace justanlsp
