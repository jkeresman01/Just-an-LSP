#pragma once

#include <memory>

#include "../errors/ErrorCodes.h"

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
    //////////////////////////////////////////////////////////////
    void handle(const ErrorCodes errorCode);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the server not initialized error
    ///
    //////////////////////////////////////////////////////////////
    void handleServerNotInitalizedError();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the parse error
    ///
    //////////////////////////////////////////////////////////////
    void handleParseError();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the method not found error
    ///
    //////////////////////////////////////////////////////////////
    void handleMethodNotFoundError();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the internal error
    ///
    //////////////////////////////////////////////////////////////
    void handleInternalError();
};
} // namespace justanlsp
