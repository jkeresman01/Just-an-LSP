#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "../params/DidChangeTextDocumentParams.h"
#include "RequestMessage.h"

namespace justanlsp
{
class DidChangeTextDocumentRequest : public RequestMessage
{
  public:
    DidChangeTextDocumentRequest(const nlohmann::json &jsonRPC);

    std::shared_ptr<DidChangeTextDocumenParams> getParams() const { return m_didChangeTextDocumentParams; };

  private:
    void setParams(const nlohmann::json &jsonRPC);

  private:
    std::shared_ptr<DidChangeTextDocumenParams> m_didChangeTextDocumentParams;
};
} // namespace justanlsp
