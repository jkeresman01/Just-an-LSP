#pragma once

#include <string>

#include "../errors/ErrorCodes.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ResponseError
///
/// @brief Represents an error response in JSON-RPC.
///        This class encapsulates the error code and a message
///        describing the error encountered during a request.
///
//////////////////////////////////////////////////////////////
class ResponseError
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor for ResponseError.
    ///
    /// Constructs a ResponseError with default values.
    ///
    //////////////////////////////////////////////////////////////
    ResponseError() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a ResponseError with a specific code and message.
    ///
    /// @param code    The ErrorCodes enumeration representing the error code.
    /// @param message A string providing a detailed message about the error.
    ///
    //////////////////////////////////////////////////////////////
    ResponseError(const ErrorCodes &code, const std::string &message);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The error code representing the type of error.
    ///
    //////////////////////////////////////////////////////////////
    ErrorCodes m_code;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A message providing additional information about the error.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_message;
};

} // namespace justanlsp
