#include "FakeDiagnosticsProvider.h"

namespace justanlsp
{

std::vector<Diagnostic> FakeDiagnosticsProvider::getDiagnostics(const std::string &document,
                                                                const Position &position)
{
    std::vector<Diagnostic> diagnostics;
    fillFakeDiagnostics();
    return diagnostics;
}

void FakeDiagnosticsProvider::fillFakeDiagnostics(std::vector<Diagnostic> &diagnostics)
{
    diagnostics.emplace_back(Range{10, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                             "This is really big error msg!!!");
    diagnostics.emplace_back(Range{20, 20}, DiagnosticSeverity::WARNING, "Source is this stuff",
                             "This is really big warning msg!!!");
    diagnostics.emplace_back(Range{30, 30}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                             "This is really big information msg!!!");
    diagnostics.emplace_back(Range{40, 40}, DiagnosticSeverity::HINT, "Source is this stuff",
                             "This is really big hint msg!!!");
}

} // namespace justanlsp
