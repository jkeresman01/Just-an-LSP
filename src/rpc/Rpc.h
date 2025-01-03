#pragma once

#include <string>

#include "../enums/RequestType.h"
#include "../messages/Message.h"
#include "../utils/Convert.h"
#include "../utils/Logger.h"

namespace justanlsp
{
/////////////////////////////////////////////////////////////////////
///
/// @class Rpc
///
/// @brief Responsible for read and sending messages defined by
///        language server protocol
///
/////////////////////////////////////////////////////////////////////
class Rpc
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    Rpc() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Send Message defined by language server protocol
    ///
    /// @param response
    ///
    /////////////////////////////////////////////////////////////////////
    static void send(const Message &response) { std::cout << response << std::endl; }

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Read JSON RPC request
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string read();

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Read content length from JSON RPC request
    ///
    /////////////////////////////////////////////////////////////////////
    static uint32_t readContentLength();
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline std::string Rpc::read()
{
    uint32_t contentlength = readContentLength();

    std::string content(contentlength, ' ');
    std::cin.read(&content[0], contentlength);

    return content;
}

inline uint32_t Rpc::readContentLength()
{
    std::string header;
    uint32_t contentLength = 0;

    while (getline(std::cin, header))
    {
        header.erase(0, header.find_first_not_of(" \t\r\n\v\f"));
        header.erase(header.find_last_not_of(" \t\r\n\v\f") + 1);

        if (header.substr(0, 16) == "Content-Length: ")
        {
            contentLength = std::stoul(header.substr(16));
        }

        if (header.empty())
        {
            return contentLength;
        }
    }
}

} // namespace justanlsp
