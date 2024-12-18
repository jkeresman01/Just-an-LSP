#pragma once

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @enum ExitStatus
///
/// @brief Describes the status with which JustAnLSP Server exited
///
///
//////////////////////////////////////////////////////////////
enum ExitStatus
{

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Successfull shutdown of JustAnLSPServer
    ///
    //////////////////////////////////////////////////////////////
    SUCCESS = 0,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unsuccessfull shutdown of JustAnLSPServer
    ///
    //////////////////////////////////////////////////////////////
    FAILURE = 1,
};
} // namespace justanlsp
