#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../../errors/ErrorCodes.h"

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
    //////////////////////////////////////////////////////////////
    ResponseError() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a ResponseError with a specific code and message.
    ///
    /// @param errorCode
    /// @param message
    ///
    //////////////////////////////////////////////////////////////
    ResponseError(const ErrorCodes &errorCode, const std::string &message);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for error code
    ///
    /// @return Error code
    ///
    //////////////////////////////////////////////////////////////
    ErrorCodes getErrorCode() const { return m_errorCode; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for error message
    ///
    /// @return Error message
    ///
    //////////////////////////////////////////////////////////////
    std::string getErrorMessage() const { return m_message; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of ResponseError
    ///
    /// @return String representation of ResponseError
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const;

    ///////////////////////////////////////////////////////////////
    ///
    /// @brief Sereializes ResponseEror to JSON format
    ///
    /// @return ResponseError in JSON formt
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The error code representing the type of error.
    ///
    //////////////////////////////////////////////////////////////
    ErrorCodes m_errorCode;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A message providing additional information about the error.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_message;
};

} // namespace justanlsp
