#pragma once

#include <string>

#include "../enums/DiagnosticSeverity.h"
#include "Range.h"

namespace justanlsp
{
class Diagnostic
{
  public:
    Diagnostic(const Range &range, const DiagnosticSeverity &severity, const std::string &source,
               const std::string &message)
        : m_range(range), m_severity(severity), m_source(source), m_message(message){};

  private:
    Range m_range;
    DiagnosticSeverity m_severity;
    std::string m_source;
    std::string m_message;
};
} // namespace justanlsp
