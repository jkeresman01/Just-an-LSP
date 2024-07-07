#pragma once

#include <optional>
#include <string>

#include "ErrorCodes.h"

namespace lsp
{

class ResponseError
{
    public:
        ResponseError(ErrorCodes code,
                     const std::string& message);

        void setData(const std::string& data);

    private:
        ErrorCodes m_code;
        std::string m_message;
        std::optional<std::string> m_data;
};

} // lsp[
