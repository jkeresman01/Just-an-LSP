#pragma once

#include <string>

#include "IDiagnosticsProvider.h"

namespace justanlsp
{
    class ClangDiagnosticsProvider : public IDiagnosticsProvider
    {
        public:
        std::vector<Diagnostic> getDiagnostics(const std::string &document, const Position &position) override;
    };
}
