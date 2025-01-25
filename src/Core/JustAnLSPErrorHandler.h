#pragma once

#include <memory>
#include <string>

#include "../Errors/ErrorCodes.h"
#include "../Messages/Response/ResponseError.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class JustAnLSPErrorHandler
///
/// @brief Responsible for handling JustAnLSP errors
///
//////////////////////////////////////////////////////////////
class JustAnLSPErrorHandler
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    JustAnLSPErrorHandler() = default;
    JustAnLSPErrorHandler(const JustAnLSPErrorHandler &) = delete;
    JustAnLSPErrorHandler(JustAnLSPErrorHandler &&) = delete;
    JustAnLSPErrorHandler &operator=(const JustAnLSPErrorHandler &) = delete;
    JustAnLSPErrorHandler &operator=(JustAnLSPErrorHandler &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the server not initialized error
    ///
    /// @param message id
    ///
    //////////////////////////////////////////////////////////////
    void handleServerNotInitalizedError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the parse error
    ///
    /// @param message id
    ///
    //////////////////////////////////////////////////////////////
    void handleParseError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the method not found error
    ///
    /// @param message id
    ///
    //////////////////////////////////////////////////////////////
    void handleMethodNotFoundError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the internal error
    ///
    /// @param message id
    ///
    //////////////////////////////////////////////////////////////
    void handleInternalError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the invalid request after shutdown
    ///
    /// @param message id
    ///
    //////////////////////////////////////////////////////////////
    void handleReceivedReqAfterShutdownError(int64_t id);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the error
    ///
    /// @param responseError
    /// @param id
    ///
    //////////////////////////////////////////////////////////////
    void handleError(const ResponseError &responseError, int64_t id);
};
} // namespace justanlsp
