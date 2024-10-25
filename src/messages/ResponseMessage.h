#pragma once

#include <optional>
#include <string>

#include "Message.h"
#include "ResponseError.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ResponseMessage
///
/// @brief A Response Message sent as a result of a request in
///        JSON-RPC, conforming to the JSON-RPC specification.
///        If a request doesn’t provide a result value, the
///        receiver of the request still needs to return a
///        response message. The result property of the
///        ResponseMessage should be set to null in this case
///        to signal a successful request.
///
//////////////////////////////////////////////////////////////
class ResponseMessage : public Message
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Builder class for constructing a ResponseMessage
    ///
    //////////////////////////////////////////////////////////////
    class Builder;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the result of the response.
    ///
    /// @return A constant reference to the result string.
    ///
    //////////////////////////////////////////////////////////////
    const std::string &getResult() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the error object in case the request fails.
    ///
    /// @return A constant reference to the ResponseError object.
    ///
    //////////////////////////////////////////////////////////////
    const ResponseError &getResponseError() const;

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The result of the request. This member is required
    ///        on success and should be set to null if there was
    ///        no result value.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_result;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The error object in case a request fails.
    ///
    //////////////////////////////////////////////////////////////
    ResponseError m_responseError;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the ResponseMessage with the provided
    ///        jsonRPC version, result, and error.
    ///
    /// @param jsonRPC         The jsonRPC version (e.g., "2.0").
    /// @param result          The result of the request (if successful).
    /// @param responseError   The error object (if the request fails).
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage(const std::string &jsonRPC, const std::string &result,
                    const ResponseError &responseError);
};

//////////////////////////////////////////////////////////////
///
/// @class ResponseMessage::Builder
///
/// @brief Builder pattern for constructing instances of
///        ResponseMessage. It allows step-by-step construction
///        of a ResponseMessage object.
///
//////////////////////////////////////////////////////////////
class ResponseMessage::Builder
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Builds the ResponseMessage object using the values
    ///        provided via the builder's methods.
    ///
    /// @return A fully constructed ResponseMessage object.
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage build() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sets the JSON-RPC version for the ResponseMessage.
    ///
    /// @param jsonRPC   The jsonRPC version (e.g., "2.0").
    ///
    /// @return A reference to the Builder object for chaining.
    ///
    //////////////////////////////////////////////////////////////
    Builder &withJsonRPC(const std::string &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sets the result of the request for the ResponseMessage.
    ///
    /// @param result    The result string of the request.
    ///
    /// @return A reference to the Builder object for chaining.
    ///
    //////////////////////////////////////////////////////////////
    Builder &withResult(const std::string &result);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sets the error object in case of a request failure.
    ///
    /// @param responseError    The ResponseError object.
    ///
    /// @return A reference to the Builder object for chaining.
    ///
    //////////////////////////////////////////////////////////////
    Builder &withResponseError(const ResponseError &responseError);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the JSON-RPC version for the ResponseMessage
    ///        during the construction process.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_jsonRPC;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the result of the request during the
    ///        construction process.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_result;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the error object in case of failure during
    ///        the construction process.
    ///
    //////////////////////////////////////////////////////////////
    ResponseError m_responseError;
};

} // namespace justanlsp
